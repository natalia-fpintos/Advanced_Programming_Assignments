#include "Server.h"

Server::Server() : Comms(5000) {}

Server::Server(int port) : Comms(port) {}

void Server::bindSocket() throw (BindSocketException) {
  int bindResult = bind(socketRef, (struct sockaddr*)&socketAddress, sizeof(socketAddress));

  if (bindResult == -1) {
    throw BindSocketException(errno);
  }
}
