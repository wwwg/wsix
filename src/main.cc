#include "WebSocket.h"

int main(int argc, char** argv) {
	wsix::WebSocket w("echo.websocket.org", 80);
	w.connect();
	char* test_buf = "asdfghi";
	size_t test_siz = 8;
	w.write(test_buf, test_siz, wsix::OpCode::binary);
	return 0;
}