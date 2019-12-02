//
// Created by vl_sys on 2019-11-29.
// 프로그램 구동부 입니다.
//

#ifndef SERVERSOCKETINFO_APPLICATION_H
#define SERVERSOCKETINFO_APPLICATION_H
#include <boost/asio.hpp>
#include <thread>
#include <cstdio>
#include <string>
#include <utility>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "StatusJSON/LsJson.h"

using boost::property_tree::ptree;
using namespace boost::asio;
using namespace boost::system;
using namespace std;
using boost::asio::ip::tcp;

class LinuxStatusClient
{
private:
    LsJson rj;
    tcp::endpoint ep;
    tcp::socket *_socket;
    bool is_connected = false;
    bool is_loaded = false;
public:
    bool isConnected() const;
    bool isLoaded() const;
    ~LinuxStatusClient()
    {
        if(_socket != nullptr) {
            _socket->close();
            delete _socket;
        }
    }
private:
    string name;
    thread service_thread;

public:
    LinuxStatusClient(io_service &_io_service, const string& setting);

    void connect();
    static void connect_err(boost::system::error_code& err);
    static void connect_err(const string& msg);
    void server_handshake();
    void service();
};


class Setting
{
public:
    const string &getIp() const;
    int getPort() const;
    const string &getClientName() const;
    Setting(const string& setting_file);
private:
    string ip;
    int port;
    string client_name;

};


#endif //SERVERSOCKETINFO_APPLICATION_H
