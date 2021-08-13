#pragma once

#include "Exceptions/CreateSocketException.h"
#include "sys/socket.h"
#include "Exceptions/SetSocketOptionsException.h"
#include "Exceptions/CloseSocketException.h"
#include <unistd.h>
#include <netdb.h>
#include <iostream>

class Comms {
protected:
  int port;
  struct sockaddr_in socketAddress;
  int socketRef;

public:
  Comms(int port);
  void createSocket(int type) throw (CreateSocketException, SetSocketOptionsException);
  void setSocketOpts(int option) throw (SetSocketOptionsException);
  void closeSocket() throw (CloseSocketException);
  enum SocketType {
    TCP = SOCK_STREAM,
    UDP = SOCK_DGRAM
  };
};
