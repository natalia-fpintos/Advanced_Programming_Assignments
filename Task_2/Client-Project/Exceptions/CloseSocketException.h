#include "ExceptionWithMessage.h"

class CloseSocketException: public ExceptionWithMessage {
private:
  int errorNum;

public:
  CloseSocketException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Could not close socket";
  }
  int getError() {
    return errorNum;
  }
};