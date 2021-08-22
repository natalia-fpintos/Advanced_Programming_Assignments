#include "ExceptionWithMessage.h"

class BindSocketException: public ExceptionWithMessage {
public:
  BindSocketException(int errorNum) : ExceptionWithMessage(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket failed to bind";
  }
};
