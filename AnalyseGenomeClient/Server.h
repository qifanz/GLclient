#pragma once
#include <string>
using namespace std;
class Server
{
public:
	Server();
	Server(string addr, int port);
	~Server();
	string getAddr();
	int getPort();

private:
	string addr;
	int port;
};

