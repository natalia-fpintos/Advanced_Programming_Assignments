#include <exception>

class StartChatException: public std::exception {
public:
  virtual const char* what() const throw() {
    return "[ERROR] - Could not start the chat";
  }
};