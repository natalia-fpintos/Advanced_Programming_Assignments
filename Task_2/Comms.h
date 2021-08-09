#pragma once

#include "Exceptions/CreateSocketException.h"
#include "sys/socket.h"
#include "Exceptions/SetSocketOptionsException.h"
#include <unistd.h>
#include <netdb.h>
#include <iostream>

class Comms {
private:
  int port;

protected:
  struct sockaddr_in socketAddress;
  int socketRef;

public:
  Comms(int port);
  void createSocket(int type) throw (CreateSocketException, SetSocketOptionsException);
  void setSocketOpts(int option) throw (SetSocketOptionsException);
  static enum SocketType {
    TCP = SOCK_STREAM,
    UDP = SOCK_DGRAM
  };
};
