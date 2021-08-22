#include "ExceptionWithMessage.h"

class ListenSocketException: public ExceptionWithMessage {
public:
  ListenSocketException(int errorNum) : ExceptionWithMessage(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket could not listen on port";
  }
  int getError() {
    return errorNum;
  }
};