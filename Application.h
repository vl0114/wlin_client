//
// Created by vl_sys on 2019-11-29.
//

#ifndef SERVERSOCKETINFO_APPLICATION_H
#define SERVERSOCKETINFO_APPLICATION_H
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <vector>
#include <list>
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
    void connect_err(boost::system::error_code& err);
    void connect_err(const string& msg);
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


//PyObject* GetSystem

/*
class ThreadPool {
public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();

    // job 을 추가한다.
    template <class F, class... Args>
    std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(
            F&& f, Args&&... args);

private:
    size_t num_threads_;
    std::vector<std::thread> worker_threads_;
    std::queue<std::function<void()>> jobs_;
    std::condition_variable cv_job_q_;
    std::mutex m_job_q_;

    bool stop_all;

    void WorkerThread();
};
*/



#endif //SERVERSOCKETINFO_APPLICATION_H
