#include "Server.h"

Server::Server() : Comms(5000) {}

Server::Server(int port) : Comms(port) {}

void Server::bindSocket() throw (BindSocketException) {
  int bindResult = bind(socketRef, (struct sockaddr*)&socketAddress, sizeof(socketAddress));

  if (bindResult == -1) {
    throw BindSocketException(errno);
  }
}

void Server::listenSocket() throw (ListenSocketException) {
  int listenResult = listen(socketRef, SOMAXCONN);
  if (listenResult == -1) {
    throw ListenSocketException(errno);
  }
  std::cout << "Listening on port " << port << std::endl;
}
