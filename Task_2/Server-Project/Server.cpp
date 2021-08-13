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

void Server::acceptSocket() throw (AcceptSocketException) {
  sockaddr_in from;
  socklen_t clientSocketLength, clientSocketTypeLength;
  int socketOptions, socket_type;
  clientSocketTypeLength = sizeof(socket_type);
  socketOptions = getsockopt(socketRef, SOL_SOCKET, SO_TYPE, (char *)&socket_type, &clientSocketTypeLength);
  clientSocketLength = sizeof(from);
  int acceptSocket = accept(socketRef, (sockaddr *)&from, &clientSocketLength);
  if (acceptSocket == -1) {
    throw AcceptSocketException(errno);
  }
}