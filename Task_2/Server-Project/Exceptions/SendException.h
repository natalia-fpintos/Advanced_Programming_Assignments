#include "ExceptionWithMessage.h"

class SendException: public ExceptionWithMessage {
private:
  int errorNum;

public:
  SendException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Could not send message";
  }
  int getError() {
    return errorNum;
  }
};