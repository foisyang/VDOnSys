#pragma once

#include <netinet/in.h>

class HostAddress
{
private:
    struct sockaddr_in m_addr;
    int m_length;
public:
    HostAddress();
    HostAddress(int sin_family, const char *ip, unsigned short port);
    ~HostAddress();
    void SetIp(const char *ip);
    const char *GetIp();
    void SetPort(unsigned short port);
    const unsigned short GetPort();
    struct sockaddr_in *GetAddress();
    int GetLength();
};
