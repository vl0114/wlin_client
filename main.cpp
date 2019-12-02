#include <iostream>
#include <string>
#include "Application.h"
#include "LinuxStatus/Linuxstatus.h"
#include <filesystem>
#include <unistd.h>
#include <boost/asio.hpp>
#include "StatusJSON/LsJson.h"

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;



int main() {

    io_service service;


    LinuxStatusClient app(service, "./setting.json");

    if(!app.isLoaded())
    {
        cout << "Setting File Error\nProgram will end..." << endl;
        exit(-1);
    }

    app.connect();

    thread t;
    if(app.isConnected())
    {
        t = thread(&LinuxStatusClient::service, &app);
        t.join();
    }


    /*boost::asio::io_service data_io;
    tcp::endpoint server_endpoint(ip::address::from_string(server_address), server_port);
    tcp::socket data_socket(data_io);
    boost::system::error_code err;

    cout << "준비완료" << endl;

    data_socket.connect(server_endpoint, err);

    if(err)
    {
        cout << "can't connect to server.." << endl;
        exit(-1);
    }
    char buf[100];
    // data_socket.read_some(buffer(buf, 100));
    data_socket.async_read_some()
    //cout << buf << endl;
    bind*/
    return 0;
}