#include "Server.h"
#include "Client.h"

//#define SERVER
#define CLIENT

int main () {
  try {
    #ifdef SERVER
    Server *server = new Server();
    server->createSocket(Comms::TCP);
    server->bindSocket();
    server->listenSocket();
    server->acceptSocket();
    #endif

    #ifdef CLIENT
    Client *client = new Client();
    client->createSocket(Comms::TCP);
    client->connectSocket();
    client->sendMsg();
    #endif
  } catch (...) {
    std::cout << " Error " << std::endl;
  }
}
