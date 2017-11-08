#ifndef _WSIX_WEBSOCKET_H
#define _WSIX_WEBSOCKET_H

// C imports
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h> 

// CXX imports
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#define SERVER_KEY "6hgCA/HMnPWzCz6qq2bWB3/YSFw="
#define READ_BUFFER_LEN (size_t)256
#define INITIAL_READ_BUF_LEN 512

namespace wsix {
	class WebSocket {
	public:
		WebSocket(string, int);
		WebSocket(struct hostent*, struct sockaddr_in, string);
		bool connect(void);
		void read();
		char* read(size_t);
	private:
		string uri;
		int port;
		int fd;
		struct sockaddr_in serverAddress;
    	struct hostent* server;
    	string httpHandShake;
	};
};

#endif