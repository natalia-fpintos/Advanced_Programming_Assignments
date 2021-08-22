#include "ExceptionWithMessage.h"

class SetSocketOptionsException: public ExceptionWithMessage {
public:
  SetSocketOptionsException(int errorNum) : ExceptionWithMessage(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - There was a problem setting the socket options";
  }
};
