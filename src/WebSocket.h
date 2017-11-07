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
		WebSocket(string);
	private:
		string uri;
	};
};

#endif