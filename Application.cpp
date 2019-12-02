//
// Created by vl_sys on 2019-11-29.
//

#include "Application.h"

LinuxStatusClient::LinuxStatusClient(boost::asio::io_service &_io_service, const string& setting) {
    _socket = new tcp::socket(_io_service);
    Setting *s;
    try {
        s = new Setting(setting);
    }
    catch (...)
    {
        return ;
    }

    ep.address(ip::address::from_string(s->getIp()));
    ep.port(s->getPort());
    name = s->getClientName();
    is_loaded = true;
    delete s;
}

bool LinuxStatusClient::isLoaded() const {
    return is_loaded;
}

void LinuxStatusClient::connect() {
    boost::system::error_code err;
    _socket->connect(ep, err);
    if(err)
        connect_err(err);
    else
        server_handshake();
}

void LinuxStatusClient::connect_err(boost::system::error_code& err) {
    cout << "Server Connection Err: "<< err.message() << endl;
}
void LinuxStatusClient::connect_err(const string &msg)
{
    cout << msg << endl;
}

void LinuxStatusClient::server_handshake() {
    ptree hsk_root;

    hsk_root.put("type", "client_hello");
    hsk_root.put("name", name);
    stringstream s;
    char r[100] = {0};

    boost::property_tree::write_json(s, hsk_root);

    _socket->write_some(buffer(s.str()));
    _socket->read_some(buffer(r, 100));
    if(!strcmp("ok", r) || !strcmp("ok\n", r))
    {
        is_connected = true;
    }
    else{
        string msg = "Server Connection Error | ";
        msg += r;
        connect_err(msg);
    }
}

void LinuxStatusClient::service() {
    if(!is_connected)
        return;
    cout << name << " start" << endl;

    char buff[2048];

    while (true)
    {
        boost::system::error_code err;
        _socket->read_some(buffer(buff, 2048), err);
        if(err)
        {
            _socket->close();
            is_connected = false;
            cout << err.message() << " connection end" << endl;
            return;
        }

        string msg(buff);
        stringstream s;
        // cout << msg << endl;
        s.str("");
        s << msg;
        ptree req;
        string rep;

        try {
            boost::property_tree::read_json(s, req);

            auto type = req.get<string>("type");
            if(type == "request") // 정보 요청
            {
                auto req_type = req.get<string>("req");
                if(req_type == "cpu")
                {
                    rj.getCpus(rep);
                    _socket->write_some(buffer(rep));
                }
                else if(req_type == "mem")
                {
                    rj.getMem(rep);
                    _socket->write_some(buffer(rep));
                }
                else if(req_type == "proc")
                {
                    rj.getProcs(rep);
                    _socket->write_some(buffer(rep));
                }
                else if(req_type == "name")
                {
                    rj.getSystemName(rep);
                    _socket->write_some(buffer(rep));
                }
            }
            else if(type == "signal") // 시그널 요청
            {
                int pid = req.get<int>("pid");
                int sig = req.get<int>("sig");
                Process p(pid);
                if(p.IsOk())
                    p.SendSignal(sig);
                _socket->write_some(::buffer(R"({"type": "ok"})"));
            }
            else if(type == "stop") // 프로그램 종료 요청
            {
                _socket->close();
                _socket->write_some(::buffer(R"({"type": "ok"})"));
                break;
            }
            else{
                _socket->write_some(buffer(R"({"type": "unknown_req"})"));
            }

        }
        catch(...) {
            cout << "json read err" << endl;
            _socket->write_some(buffer(R"({"type": "unknown_msg"})"));
            continue;
        }

        usleep(1);
    }

}

bool LinuxStatusClient::isConnected() const {
    return is_connected;
}

const string &Setting::getIp() const {
    return ip;
}

int Setting::getPort() const {
    return port;
}

const string &Setting::getClientName() const {
    return client_name;
}

Setting::Setting(const string& setting_file) {
    ptree setting_root;
    boost::property_tree::read_json(setting_file, setting_root);

    ip = setting_root.get<string>("server_ip");
    port = setting_root.get<int>("port");
    client_name = setting_root.get<string>("client_name");
}
