#include <exception>

class SendException: public std::exception {
private:
  int errorNum;

public:
  SendException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Could not send message";
  }
  int getError() {
    return errorNum;
  }
};