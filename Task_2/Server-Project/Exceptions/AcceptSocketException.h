#include "ExceptionWithMessage.h"


class AcceptSocketException: public ExceptionWithMessage {
public:
  AcceptSocketException(int errorNum) : ExceptionWithMessage(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket failed to accept connections";
  }
};
