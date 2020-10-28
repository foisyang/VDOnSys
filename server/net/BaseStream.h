#pragma once
#include "HostAddress.h"
class BaseStream
{
private:
    int             m_fd;
public:
    BaseStream();
    BaseStream(int fd);
    ~BaseStream();
    void SetFd(int fd);
    int GetFd() const;
    int Read(char *buff, const int buff_len);
    int Read(char *buff, const int buff_len, struct timeval *tv);
    int Read(char *buff, const int buff_len, HostAddress &remote_addr);
    int Read(char *buff, const int buff_len, HostAddress &remote_addr, struct timeval *tv);
    int Write(const char *buff, const int buff_len);
    int Write(const char *buff, const int buff_len, struct timeval *tv);
    int Write(const char *buff, const int buff_len, HostAddress remote_addr);
    int Write(const char *buff, const int buff_len, HostAddress remote_addr, struct timeval *tv);
};
