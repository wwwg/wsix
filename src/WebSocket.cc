#include "WebSocket.h"

wsix::WebSocket::WebSocket(string _uri, int _port) {
	uri = _uri;
	port = _port;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		throw "Failed to create socket";
		return;
	}
	server = gethostbyname(_uri.c_str());
	if (server == NULL) {
		throw "Failed to resolve server";
		return;
	}
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	memcpy((char *)&serverAddress.sin_addr.s_addr,
		(char *)server->h_addr,
        server->h_length);
	serverAddress.sin_port = htons(_port);
}
wsix::WebSocket::WebSocket(struct hostent* _host, struct sockaddr_in _addr) {
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		throw "Failed to create socket";
		return;
	}
	server = _host;
	serverAddress = _addr;
}
bool wsix::WebSocket::connect() {
	int success = ::connect(fd, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
	if (success < 0) {
		return false;
	}
	cout << "connected" << endl;
	return true;
}