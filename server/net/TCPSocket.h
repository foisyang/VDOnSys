#pragma once

#include "BaseSocket.h"

class TCPSocket:public BaseSocket
{
private:
    /* data */
public:
    TCPSocket(/* args */);
    TCPSocket(int sin_farmly, int flag, int protocol);
    TCPSocket(int fd);
    ~TCPSocket();
    TCPSocket &operator=(const TCPSocket &other);
    HostAddress GetRemoteAddr() const;
    void SetRemoteAddr(const HostAddress remode_hostaddr);
    int Connect(HostAddress hostaddr);
    int Read(char *buff, const int buff_len);
    int Read(char *buff, const int buff_len, struct timeval *tv);
    int Write(char *buff, const int buff_len);
    int Write(char *buff, const int buff_len, struct timeval *tv);
protected:
    void Create();
    HostAddress m_remote_addr;
};
