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
wsix::WebSocket::WebSocket(struct hostent* _host, struct sockaddr_in _addr, string _hostUri) {
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		throw "Failed to create socket";
		return;
	}
	server = _host;
	serverAddress = _addr;
	uri = _hostUri;
}
bool wsix::WebSocket::connect() {
	stringstream hsstream;
	hsstream << "GET ws://" << uri << "/ HTTP/1.1\r\n" <<
	"Host: " << uri << "\r\n" <<
	"Connection: Upgrade\r\n" <<
	"Upgrade: websocket\r\n" <<
	"Sec-WebSocket-Version: 13\r\n" <<
	"User-Agent: wsix\r\n" <<
	"Accept-Language: en-US,en;q=0.8\r\n" <<
	"Sec-WebSocket-Key: EATKMOE1Y+WetOtQeSjh/w==\r\n\r\n";
	httpHandShake = hsstream.str();
	int success = ::connect(fd, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
	if (success < 0) return false;
	int bytesWrote = write(fd, httpHandShake.c_str(), httpHandShake.length() + 1);
	char indata[READ_BUFFER_LEN];
	int bytesRead = read(fd, indata, READ_BUFFER_LEN);
	cout << indata << endl;
	return true;
}