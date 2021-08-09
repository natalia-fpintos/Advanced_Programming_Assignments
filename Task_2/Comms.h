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
  struct sockaddr_in socketAddress;
  int socketRef;

public:
  Comms(int port);
  void createSocket(int type) throw (CreateSocketException, SetSocketOptionsException);
};
