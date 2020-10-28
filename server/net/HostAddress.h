#pragma once

#include <netinet/in.h>

class HostAddress
{
public:
    HostAddress();
    HostAddress(int sin_family, const char *ip, unsigned short port);
    ~HostAddress();
    void SetIp(const char *ip);
    char *GetIp() const;
    void SetPort(unsigned short port);
    unsigned short GetPort() const;
    struct sockaddr_in *GetAddress();
    int GetLength();
private:
    int                     m_length;
    struct sockaddr_in      m_addr;
};
