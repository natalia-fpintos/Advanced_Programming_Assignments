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

  // Setting socket-level options to allow reuse
  int option = 1;
  if (setsockopt(socketRef, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option)) == -1) {
    throw SetSocketOptionsException(errno);
  }
}
