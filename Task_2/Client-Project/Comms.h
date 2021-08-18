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
  int BUFFER_SIZE = 200;
  int port;
  struct sockaddr_in socketAddress;
  int socketRef;
  std::string getMessage();
  virtual std::string sendMsg() throw (SendException) = 0;
  virtual void receiveData(char* buffer, int size) throw (ReceiveException) = 0;

public:
  Comms(int port);
  void createSocket(int type) throw (CreateSocketException, SetSocketOptionsException);
  void setSocketOpts(int option) throw (SetSocketOptionsException);
  void closeSocket() throw (CloseSocketException);
  virtual void startChat() throw (StartChatException) = 0;
  bool checkQuit(char* msg);
  enum SocketType {
    TCP = SOCK_STREAM,
    UDP = SOCK_DGRAM
  };
};
