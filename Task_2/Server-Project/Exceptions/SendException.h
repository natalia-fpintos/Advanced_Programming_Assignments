#include "ExceptionWithMessage.h"

class SendException: public ExceptionWithMessage {
public:
  SendException(int errorNum) : ExceptionWithMessage(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Could not send message";
  }
};