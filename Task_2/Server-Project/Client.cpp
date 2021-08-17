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

std::string Client::sendMsg() throw (SendException) {
  std::string msg = getMessage();
  if (send(socketRef, msg.c_str(), msg.size() + 1, 0) == -1) {
    throw SendException(errno);
  } else {
    std::cout << "Message sent!" << std::endl;
  }
  return msg;
}

void Client::receiveData(char* buffer, int size) throw (ReceiveException) {
  if (recv(socketRef, buffer, size, 0) == -1) {
    std::cout << errno << std::endl;
    throw ReceiveException();
  } else {
    std::cout << "Message received!" << std::endl;
  }
}

void Client::startChat() throw (class StartChatException) {
  while (true) {
    std::string msg = sendMsg();
    char msg_str[msg.length() + 1];
    strcpy(msg_str, msg.c_str());
    if (checkQuit(msg_str)) {
      std::cout << "[CLIENT] Chat terminated" << std::endl;
      break;
    }

    char buffer[BUFFER_SIZE];
    receiveData(buffer, BUFFER_SIZE);
    std::cout << buffer << std::endl;
    if (checkQuit(buffer)) {
      std::cout << "[CLIENT] Chat terminated" << std::endl;
      break;
    }
  }
  closeSocket();
}
