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
    server->receiveData();
    server->sendMsg();
    #endif

    #ifdef CLIENT
    Client *client = new Client();
    client->createSocket(Comms::TCP);
    client->connectSocket();
    client->sendMsg();
    client->receiveData();
    #endif
  } catch (...) {
    std::cout << " Error " << std::endl;
  }
}
