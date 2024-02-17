#include <client.h>

TCPClient::TCPClient() {
    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    if (WSAStartup(ver, &wsData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        exit(1);
    }

    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }
}

bool TCPClient::Connect(const char* ipAddress, const int port) {
    // Connect to the server
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress, &hint.sin_addr);

    if (connect(clientSocket, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR) {
        std::cerr << "Can't connect to server" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        connected = false;
        return false;
    }
    connected = true;
    return true;
}

void TCPClient::SendMessage(const std::string& message) {
    if (message.size() > 0) {
        // Send the text
        send(clientSocket, message.c_str(), message.size(), 0);
    }
}

void TCPClient::ReceiveMessages() {
    char buf[4096];
    while (true) {
        ZeroMemory(buf, 4096);

        // Wait for server to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR) {
            std::cerr << "Error in recv(). Quitting" << std::endl;
            break;
        }

        if (bytesReceived == 0) {
            std::cout << "Server disconnected" << std::endl;
            break;
        }

        std::cout << "Server says: " << std::string(buf, 0, bytesReceived) << std::endl;
    }
}

TCPClient::~TCPClient() {
    // Close down everything
    closesocket(clientSocket);
    WSACleanup();
}
