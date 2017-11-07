#include "WebSocket.h"

wsix::WebSocket::WebSocket(string _uri, int _port) {
	uri = _uri;
	port = _port;
	sock = socket(AF_INET, SOCKET_STREAM, 0);
	if (sock < 0) {
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
	uri = _uri;
	port = _port;
	sock = socket(AF_INET, SOCKET_STREAM, 0);
	if (sock < 0) {
		throw "Failed to create socket";
		return;
	}
	server = _host;
	serverAddress = _addr;
}