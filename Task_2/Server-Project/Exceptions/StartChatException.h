#include "ExceptionWithMessage.h"

class StartChatException: public ExceptionWithMessage {
public:
  virtual const char* what() const throw() {
    return "[ERROR] - Could not start the chat";
  }
};