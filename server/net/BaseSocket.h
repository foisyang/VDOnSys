#pragma once

#include "BaseStream.h"

class BaseSocket
{
private:
    /* data */
public:
    BaseSocket(/* args */);
    BaseSocket(int sin_farmly, int type, int protocol);
    ~BaseSocket();
    int GetSocket() const { return m_fd; }
	void SetSocket(int fd);
	HostAddress GetAddress();
	int Bind(HostAddress hostaddr);
	int Close();
protected:
	void Create(int sin_farmly, int type, int protocl);
	int                 m_fd;
    int                 m_sin_farmly;
    BaseStream*         m_stream;
};

