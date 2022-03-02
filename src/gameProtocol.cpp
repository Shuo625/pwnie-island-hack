#include "stdafx.h"
#include <netinet/in.h>
#include <sys/socket.h>

#include "commands.h"


class Server {
  public:
    std::string host;
    int port;

  public:
    Server(const std::string& host, int port);
    void listen();
};


class GameProtocol: public std::thread {
  public:
    Server *server;
        
};