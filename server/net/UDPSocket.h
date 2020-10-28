#pragma once

#include "BaseSocket.h"
class UDPSocket : public BaseSocket
{
public:
	UDPSocket();
	UDPSocket(int fd);
	~UDPSocket(void);
	int Read(char *buf, const int buf_len, HostAddress &remote_addr);
	int Read(char *buf, const int buf_len, HostAddress &remote_addr, struct timeval *tv);
	int Write(char *buf, const int buf_len, HostAddress remote_addr);
	int Write(char *buf, const int buf_len, HostAddress remote_addr, struct timeval *tv);
private:
	void Create();
};
