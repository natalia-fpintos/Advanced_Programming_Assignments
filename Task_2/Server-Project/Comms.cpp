#include "Comms.h"

Comms::Comms(int port): port(port) {
  socketAddress = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = INADDR_ANY,
      .sin_port = htons(port)
  };
}

void Comms::createSocket(int type) throw (CreateSocketException, SetSocketOptionsException) {
  socketRef = socket(AF_INET, type, 0);

  if (socketRef == -1) {
    throw CreateSocketException();
  }

  setSocketOpts(SO_REUSEADDR);
  setSocketOpts(SO_REUSEPORT);
}

void Comms::setSocketOpts(int option) throw (class SetSocketOptionsException) {
  // Setting socket-level options to allow reuse
  if (setsockopt(socketRef, SOL_SOCKET, option, &option, sizeof(option)) == -1) {
    throw SetSocketOptionsException(errno);
  }
}

void Comms::closeSocket() throw(class CloseSocketException) {
  close(socketRef);
}

std::string Comms::getMessage() {
  std::string userMsg;
  std::cout << "Please enter a message: ";
  std::getline(std::cin, userMsg);
  return userMsg;
}
