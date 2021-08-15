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
  if (send(socketRef, msg.c_str(), msg.size() + 1, 0) == -1) {
    throw SendException(errno);
  } else {
    std::cout << "Message sent!" << std::endl;
  }
}

char* Client::receiveData() throw (ReceiveException) {
  char buff[4096];
  if (recv(socketRef, buff, sizeof(buff), 0) == -1) {
    std::cout << errno << std::endl;
    throw ReceiveException();
  } else {
    std::cout << "Message received!" << std::endl;
    return buff;
  }
}

void Client::startChat() throw(class StartChatException) {
  while (1) {
    sendMsg();
    char* data = receiveData();
    std::cout << data << std::endl;
  }
}
