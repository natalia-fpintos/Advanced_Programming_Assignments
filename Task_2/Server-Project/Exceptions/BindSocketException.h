#include "ExceptionWithMessage.h"

class BindSocketException: public ExceptionWithMessage {
private:
  int errorNum;

public:
  BindSocketException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket failed to bind";
  }
  int getError() {
    return errorNum;
  }
};
