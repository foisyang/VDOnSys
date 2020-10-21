#include "HostAddress.h"

#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>

HostAddress::HostAddress()
{
    this->m_length = sizeof(struct sockaddr_in);
}

HostAddress::HostAddress(int sin_family, const char *ip, unsigned short port)
{
    this->m_addr.sin_family = sin_family;
    this->m_addr.sin_addr.s_addr = inet_addr(ip);
    this->m_addr.sin_port = htons(port);
    this->m_length = sizeof(struct sockaddr_in);
}

HostAddress::~HostAddress()
{
}

void HostAddress::SetIp(const char *ip)
{
    this->m_addr.sin_addr.s_addr = inet_addr(ip);
}

char *HostAddress::GetIp() const
{
    return inet_ntoa(this->m_addr.sin_addr);
}

void HostAddress::SetPort(const unsigned short port)
{
    this->m_addr.sin_port = htons(port);
}

unsigned short HostAddress::GetPort() const
{
    return ntohs(this->m_addr.sin_port);
}

struct sockaddr_in *HostAddress::GetAddress()
{
    return (struct sockaddr_in *)(&(this->m_addr));
}

int HostAddress::GetLength()
{
    return this->m_length;
}
