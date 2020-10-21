#include "BaseStream.h"

#include <unistd.h>
#include <stdio.h>

BaseStream::BaseStream(/* args */): m_fd(0)
{
}

BaseStream::BaseStream(int fd)
{
    this->SetFd(fd);
}

BaseStream::~BaseStream()
{
}

void BaseStream::SetFd(int fd)
{
    this->m_fd = fd;
}

int BaseStream::GetFd() const
{
    return this->m_fd;
}

int BaseStream::Read(char *buff, const int buff_len)
{
    int m_flag = read(this->m_fd, buff, buff_len);
    if (m_flag < 0)
    {
        perror("read error");
        return -1;
    }
    return 0;
}

int BaseStream::Read(char *buff, const int buff_len, struct timeval *tv)
{

}

int BaseStream::Read(char *buff, const int buff_len, HostAddress &remote_addr)
{

}

int BaseStream::Read(char *buff, const int buff_len, HostAddress &remote_addr, struct timeval *tv)
{

}

int BaseStream::Write(const char *buff, const int buff_len)
{
    int m_flag = write(this->m_fd, buff, buff_len);
    if (m_flag < 0)
    {
        perror("write error");
        return -1;
    }
    return 0;
}

int BaseStream::Write(const char *buff, const int buff_len, struct timeval *tv)
{

}

int BaseStream::Write(const char *buff, const int buff_len, HostAddress remote_addr)
{

}

int BaseStream::Write(const char *buff, const int buff_len, HostAddress remote_addr, struct timeval *tv)
{

}

