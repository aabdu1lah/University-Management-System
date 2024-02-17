#ifndef C_BUILDER_CLIENT_H
#define C_BUILDER_CLIENT_H

#include <WS2tcpip.h>
#include <thread>

#if defined(_WIN64)
#pragma link "ws2_32.a"
#else
#pragma link "ws2_32.lib"
#endif


class TCPClient {
private:
    SOCKET clientSocket;

public:
    bool connected;

    TCPClient();
    bool Connect(const char* ipAddress, int port);
    void SendMessage(const std::string& message);
    void ReceiveMessages();
    ~TCPClient();
};


#endif //C_BUILDER_CLIENT_H
