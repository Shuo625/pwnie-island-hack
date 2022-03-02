#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "gameProtocol.h"
#include "utils.h"


Server::Server(const std::string& _host, int _port, int _buffer_size) {
    host = _host;
    port = _port;
    buffer_size = _buffer_size;

    server = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(host.c_str());

    bind(server, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
}

void Server::startListen() {
    listen(server, 5);
}

std::string Server::reveiceMessage() {
    int sock;
    struct sockaddr_in sockaddr;
    socklen_t sockaddrlen = sizeof(sockaddr);

    sock = accept(this->server, (struct sockaddr *)&sockaddr, &sockaddrlen);
    std::cout << "Connected by " << sockaddr.sin_addr.s_addr << std::endl;

    char buffer[this->buffer_size];
    recv(sock, buffer, this->buffer_size, 0);

    std::string message(buffer);

    return message;
}

static void Server::sendMessage(const std::string& message, const std::string& host, int port) {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in clientaddr;
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_port = htons(port);
    clientaddr.sin_addr.s_addr = inet_addr(host.c_str());

    connect(client_socket, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
    send(client_socket, message.c_str(), message.length(), 0);
}


GameProtocol::GameProtocol(const std::string& _host, int _port, int _buffer_size) {
    server = new Server(_host, _port, _buffer_size);
    host = _host;
    port = _port;
    buffer_size = _buffer_size;
}

void GameProtocol::registerCommand(const std::string& command, Command callback) {
    this->commands[command] = callback;
}

void GameProtocol::run() {
    std::cout << "Server starts at " << this->host << ":" << this->port << std::endl;
    this->server->startListen();

    while (true) {
        std::string message = this->server->reveiceMessage();
        std::vector<std::string> message_parts = this->_parseMessage(message);
        std::string command = message_parts.at(0);
        message_parts.erase(0);
        std::vector<std::string>& arguments = message_parts;

        this->_runCommand(command, arguments);
    }
}

void GameProtocol::_runCommand(const std::string& command, const std::vector<std::string>& arguments) {
    std::cout << "Receive command " << command << " " << stringJoin(' ', arguments) << std::endl;
    this->commands[command](arguments);
}

std::vector<std::string> GameProtocol::_parseMessage(const std::string& message) {
    return stringSplit(message, ' ');
}

static void GameProtocol::call_remote_command(const std::string& message, const std::string& host="127.0.0.1", int port=8081) {
    Server::sendMessage(message, host, port);
}