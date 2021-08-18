#include "ExceptionWithMessage.h"

class CreateSocketException: public ExceptionWithMessage {
public:
  virtual const char* what() const throw() {
    return "[ERROR] - Could not create the socket";
  }
};
