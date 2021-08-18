#include "ExceptionWithMessage.h"

class SetSocketOptionsException: public ExceptionWithMessage {
private:
  int errorNum;

public:
  SetSocketOptionsException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - There was a problem setting the socket options";
  }
  int getError() {
    return errorNum;
  }
};
