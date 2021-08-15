#pragma once

#include "Exceptions/CreateSocketException.h"
#include "sys/socket.h"
#include "Exceptions/SetSocketOptionsException.h"
#include "Exceptions/CloseSocketException.h"
#include "Exceptions/ReceiveException.h"
#include "Exceptions/SendException.h"
#include "Exceptions/StartChatException.h"
#include <unistd.h>
#include <netdb.h>
#include <iostream>

class Comms {
protected:
  int port;
  struct sockaddr_in socketAddress;
  int socketRef;
  std::string getMessage();

public:
  Comms(int port);
  void createSocket(int type) throw (CreateSocketException, SetSocketOptionsException);
  void setSocketOpts(int option) throw (SetSocketOptionsException);
  void closeSocket() throw (CloseSocketException);
  virtual void sendMsg() throw (SendException) = 0;
  virtual char* receiveData() throw (ReceiveException) = 0;
  virtual void startChat() throw (StartChatException) = 0;
  enum SocketType {
    TCP = SOCK_STREAM,
    UDP = SOCK_DGRAM
  };
};
