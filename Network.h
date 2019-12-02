//
// Created by vl_sys on 2019-11-29.
//

#ifndef SERVERSOCKETINFO_NETWORK_H
#define SERVERSOCKETINFO_NETWORK_H

#include <sys/socket.h>
#include <functional>
#include <string>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

typedef struct sockaddr ADDRESS_SOCK;
typedef struct sockaddr_in ADDRESS_INET;


class Address {
protected:
    ADDRESS_SOCK* address = nullptr;
    size_t addrsock_size = 0;

public:
    Address()= default;
    Address(ADDRESS_SOCK* sadr, size_t size);
    ~Address()
    {
        delete(address);
    }
    Address(Address& copy);
    ADDRESS_SOCK* GetAddress();
    size_t GetSize();
    void SetThis(ADDRESS_SOCK* addr, size_t size);
    // void SetInet6();

    void SetInet4(const std::string &ip, int port);
};


class Socket {
private:
    int socket = -1;
    int address_family = -1;
    int protocol = -1;

public:
    void GetSocket(int af, int proto);
    void BindAddress(Address& addr);

    void SetListenQue(int size);
    void Accept(Socket &client, Address& addr);
    // Socket *Accept();

    void SendString(std::string);
    std::string ReadString();

    //void SendStringTo()
};


class Network {
};


#endif //SERVERSOCKETINFO_NETWORK_H
