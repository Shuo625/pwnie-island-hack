#ifndef GAME_PROTOCOL_H
#define GAME_PROTOCOL_H


#include "stdafx.h"


typedef void (*Command)(std::vector<std::string>);


class Server {
  public:
    std::string host;
    int port;
    int buffer_size;
    int server; // socket fd

  public:
    Server(const std::string& _host, int _port, int _buffer_size);
    void startListen();
    std::string reveiceMessage();

    static void sendMessage(const std::string& message, const std::string& host, int port);
};


class GameProtocol {
  public:
    std::string host;
    int port;
    int buffer_size;
    Server *server;
    std::map<std::string, Command> commands;

  public:
    GameProtocol(const std::string& _host, int _port, int _buffer_size);
    void registerCommand(const std::string& command, Command callback);
    void run();

    static void call_remote_command(const std::string& message, const std::string& host="127.0.0.1", int port=8081);

  private:
    void _runCommand(const std::string& command, const std::vector<std::string>& arguments);
    std::vector<std::string> _parseMessage(const std::string& message);

};


#endif /* GAME_PROTOCOL_H */