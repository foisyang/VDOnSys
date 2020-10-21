#pragma once

#include "BaseSocket.h"

class TCPSocket:public BaseSocket
{
private:
    /* data */
    void Create();
    HostAddress m_remote_addr;
public:
    TCPSocket(/* args */);
    TCPSocket(int sin_farmly, int type, int protocol);
    TCPSocket(int fd);
    ~TCPSocket();
    TCPSocket &operator=(const TCPSocket &other);
    HostAddress GetRemoteAddr() const;
    void SetRemoteAddr(const HostAddress remode_addr);
    bool Connect(HostAddress addr);
    int Read(char *buf, const int buf_len);
    int Read(char *buf, const int buf_len, struct timeval *tv);
    int Write(char *buf, const int buf_len);
    int Write(char *buf, const int buf_len, struct timeval *tv);
};
