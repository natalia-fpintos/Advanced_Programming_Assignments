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

std::string Server::sendMsg() throw (SendException) {
  std::string msg = getMessage();
  if (send(clientSocketRef, msg.c_str(), msg.size() + 1, 0) == -1) {
    throw SendException(errno);
  } else {
    std::cout << "(Sent)" << std::endl;
  }
  return msg;
}

void Server::receiveData(char* buffer, int size) throw (ReceiveException) {
  if (recv(clientSocketRef, buffer, size, 0) == -1) {
    std::cout << errno << std::endl;
    throw ReceiveException();
  } else {
    std::cout << "Message from client: ";
  }
}

void Server::startChat() throw(class StartChatException) {
  while (true) {
    char buffer[BUFFER_SIZE];
    receiveData(buffer, BUFFER_SIZE);
    std::cout << buffer << std::endl;
    if (checkQuit(buffer)) {
      std::cout << "[SERVER] Chat terminated" << std::endl;
      break;
    }
    std::string msg = sendMsg();
    char msg_str[msg.length() + 1];
    strcpy(msg_str, msg.c_str());
    if (checkQuit(msg_str)) {
      std::cout << "[SERVER] Chat terminated" << std::endl;
      break;
    }
  }
  closeSocket();
}