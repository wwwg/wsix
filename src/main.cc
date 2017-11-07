#include "WebSocket.h"

int main(int argc, char** argv) {
	wsix::WebSocket w("echo.websocket.org", 80);
	w.connect();
	return 0;
}