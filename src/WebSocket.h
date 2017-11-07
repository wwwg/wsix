#ifndef _WSIX_WEBSOCKET_H
#define _WSIX_WEBSOCKET_H

// C imports
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

// CXX imports
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace wsix {
	class WebSocket {
	public:
		WebSocket(string, int);
		WebSocket(struct hostent*, struct sockaddr_in);
	private:
		string uri;
		int port;
		sock_t sock;
		struct sockaddr_in serverAddress;
    	struct hostent* server;
	};
};

#endif