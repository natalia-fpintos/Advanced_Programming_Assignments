#include "ExceptionWithMessage.h"

class CloseSocketException: public ExceptionWithMessage {
public:
  CloseSocketException(int errorNum) : ExceptionWithMessage(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Could not close socket";
  }
  int getError() {
    return errorNum;
  }
};