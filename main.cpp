#include <iostream>
#include <string>
#include "Application.h"
#include <boost/asio.hpp>

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

    return 0;
}