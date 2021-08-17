#include "ExceptionWithMessage.h"

class ReceiveException: public ExceptionWithMessage {
public:
  virtual const char* what() const throw() {
    return "[ERROR] - There was an error receiving data";
  }
};