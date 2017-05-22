#include "stdafx.h"
#include "Server.h"


Server::Server()
{
}

Server::Server(string addr, int port)
{
	this->addr = addr;
	this->port = port;
}


Server::~Server()
{
}

string Server::getAddr()
{
	return addr;
}

int Server::getPort()
{
	return port;
}
