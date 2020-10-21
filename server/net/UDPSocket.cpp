#include "UDPSocket.h"

UDPSocket::UDPSocket()
{
}

UDPSocket::UDPSocket(int fd)
{
    this->SetSocket(fd);
}

UDPSocket::~UDPSocket(void)
{
}

int UDPSocket::Read(char *buf, const int buf_len, HostAddress &remote_addr)
{
}

int UDPSocket::Read(char *buf, const int buf_len, HostAddress &remote_addr, struct timeval *tv)
{
}

int UDPSocket::Write(char *buf, const int buf_len, HostAddress remote_addr)
{

}

int UDPSocket::Write(char *buf, const int buf_len, HostAddress remote_addr, struct timeval *tv)
{

}

void UDPSocket::Create()
{

}
