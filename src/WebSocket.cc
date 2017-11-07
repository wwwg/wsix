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
	return false;
}