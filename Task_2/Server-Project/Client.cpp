#include "Client.h"

Client::Client() : Comms(5000) {}

Client::Client(int port) : Comms(port) {}

void Client::connectSocket() throw (ConnectSocketException) {
  if (connect(socketRef, (struct sockaddr*)&socketAddress, sizeof(socketAddress)) == -1) {
    throw ConnectSocketException(errno);
  } else {
    std::cout << "Client established a connection with the server" << std::endl;
  }
}

void Client::sendMsg() throw (SendException) {
  std::string msg = getMessage();
  if (send(socketRef, &msg, msg.size(), 0) == -1) {
    throw SendException(errno);
  } else {
    std::cout << "Message sent!" << std::endl;
  }
}

std::string Client::getMessage() {
  std::string userMsg;
  std::cout << "Please enter a message: ";
  std::getline(std::cin, userMsg);
  return userMsg;
}