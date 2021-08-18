#include "ExceptionWithMessage.h"

class ConnectSocketException: public ExceptionWithMessage {
public:
  ConnectSocketException(int errorNum) : ExceptionWithMessage(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket failed to connect";
  }
};
