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
  clientSocketRef = accept(socketRef, (sockaddr *)&from, &clientSocketLength);
  if (clientSocketRef == -1) {
    throw AcceptSocketException(errno);
  }
}

void Server::sendMsg() throw (SendException) {
  std::string msg = getMessage();
  if (send(clientSocketRef, msg.c_str(), msg.size() + 1, 0) == -1) {
    throw SendException(errno);
  } else {
    std::cout << "Message sent!" << std::endl;
  }
}

void Server::receiveData() throw (ReceiveException) {
  char buff[4096];
  if (recv(clientSocketRef, buff, sizeof(buff), 0) == -1) {
    std::cout << errno << std::endl;
    throw ReceiveException();
  } else {
    std::cout << "Message received!" << std::endl;
    std::cout << buff << std::endl;
  }
}
