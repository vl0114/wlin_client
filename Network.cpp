//
// Created by vl_sys on 2019-11-29.
//

#include "Network.h"




//




void Socket::GetSocket(int af, int proto) {
    socket = ::socket(af, proto, 0);
}

void Socket::BindAddress(Address& addr) {
    int n = ::bind(socket, addr.GetAddress(), addr.GetSize());
}

void Socket::SetListenQue(int size) {
    listen(socket, size);
}

void Socket::Accept(Socket &client, Address &addr) {
    ADDRESS_SOCK* s;
    socklen_t size;
    ADDRESS_SOCK sock;

    int csock = accept(socket, &sock, &size);
    addr.SetThis(&sock, size);
    client.socket = csock;
}

void Socket::SendString(std::string data) {
    ::send(socket, data.c_str(), data.length(), 0);
}

std::string Socket::ReadString() {
    char buf[4096];
    ::recv(socket, buf, 1024, 0);
    return std::string(buf);
}

void Address::SetInet4(const std::string& ip, int port) {
    addrsock_size = sizeof(struct sockaddr_in);
    struct sockaddr_in* inet = (struct sockaddr_in*) malloc(addrsock_size);
    memset(inet->sin_zero, 0, sizeof(inet->sin_zero));
    inet->sin_family = AF_INET;
    inet->sin_port = htons(port);
    inet->sin_addr.s_addr = inet_addr(ip.c_str());
    address = (struct sockaddr*) inet;
}

Address::Address(Address &copy) {
    if(address != nullptr)
    {
        memcpy(copy.address, address, addrsock_size);
        copy.addrsock_size = addrsock_size;
    }

}

ADDRESS_SOCK *Address::GetAddress() {
    return address;
}

Address::Address(ADDRESS_SOCK *sadr, size_t size) {
    memcpy(address, sadr, size);
    addrsock_size = size;
}

size_t Address::GetSize() {
    return addrsock_size;
}

void Address::SetThis(ADDRESS_SOCK *addr, size_t size) {
    if(address != nullptr)
        free(address);
    address = (ADDRESS_SOCK*) malloc(size);
    memcpy(address, addr, size);
    addrsock_size = size;
}

