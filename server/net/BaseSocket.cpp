#include "BaseSocket.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

BaseSocket::BaseSocket(/* args */) : m_fd(0), m_stream(NULL)
{

}

BaseSocket::BaseSocket(int sin_farmly, int type, int protocol)
{
    this->Create(sin_farmly, type, protocol);
}

BaseSocket::~BaseSocket()
{
}

void BaseSocket::SetSocket(int fd)
{
    this->m_fd = fd;
    if (this->m_stream != NULL)
    {
        delete this->m_stream;
        m_stream = NULL;
    }
    m_stream = new BaseStream(this->m_fd);
}

HostAddress BaseSocket::GetAddress()
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    memset(&addr, 0, addr_len);

    getsockname(this->m_fd, ((struct sockaddr *)&addr), &addr_len);

    HostAddress hostaddr;
    hostaddr.SetIp(inet_ntoa(addr.sin_addr));
    hostaddr.SetPort(ntohs(addr.sin_port));
    return hostaddr;
}

int BaseSocket::Bind(HostAddress hostaddr)
{
    struct sockaddr_in *addr;
    //memset(&addr, 0, sizeof(struct sockaddr_in));
    //memcpy(&addr, hostaddr.GetAddress(), sizeof(struct sockaddr_in));
    addr = hostaddr.GetAddress();
    return bind(this->m_fd, (sockaddr *)addr, sizeof(struct sockaddr_in));
}

int BaseSocket::Close()
{
    return close(this->m_fd);
}

void BaseSocket::Create(int sin_family, int type, int protocl)
{
    this->m_fd = socket(sin_family, type, protocl);
    this->m_stream = new BaseStream(this->m_fd);
}