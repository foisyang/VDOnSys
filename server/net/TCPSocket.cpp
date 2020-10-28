#include "TCPSocket.h"

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

TCPSocket::TCPSocket(/* args */)
{

}
TCPSocket::TCPSocket(int sin_farmly, int flag, int protocol)
{
    BaseSocket::Create(sin_farmly, flag, protocol);
}
TCPSocket::TCPSocket(int fd)
{
    this->SetSocket(fd);
}
TCPSocket::~TCPSocket()
{

}

TCPSocket & TCPSocket::operator=(const TCPSocket &other)
{

}
HostAddress TCPSocket::GetRemoteAddr() const    
{
    return this->m_remote_addr;
}
void TCPSocket::SetRemoteAddr(const HostAddress remode_hostaddr)
{
    this->m_remote_addr.SetIp(remode_hostaddr.GetIp());
    this->m_remote_addr.SetPort(remode_hostaddr.GetPort());
}
int TCPSocket::Connect(HostAddress hostaddr)
{
    struct sockaddr_in s_addr;
    memset(&s_addr, 0, sizeof(struct sockaddr_in));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = inet_addr(hostaddr.GetIp());
    s_addr.sin_port = htons(hostaddr.GetPort());

    int ret = connect(this->GetSocket(), (struct sockaddr *)&s_addr, sizeof(struct sockaddr_in));
    if (ret<0)
    {
        std::cout << "connect error " << ret << std::endl;
    }
    if (ret == 0)
    {
        std::cout << "connect success " << ret << std::endl;
        this->SetRemoteAddr(hostaddr);
    }
    return ret;
}
int TCPSocket::Read(char *buff, const int buff_len)
{
    return this->m_stream->Read(buff, buff_len);
}
int TCPSocket::Read(char *buff, const int buff_len, struct timeval *tv)
{
    return this->m_stream->Read(buff, buff_len, tv);
}
int TCPSocket::Write(char *buff, const int buff_len)
{
    return this->m_stream->Write(buff, buff_len);
}
int TCPSocket::Write(char *buff, const int buff_len, struct timeval *tv)
{
    return this->m_stream->Write(buff, buff_len, tv);
}