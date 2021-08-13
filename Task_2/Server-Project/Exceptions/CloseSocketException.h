#include <exception>

class CloseSocketException: public std::exception {
private:
  int errorNum;

public:
  CloseSocketException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Could not close socket";
  }
  int getError() {
    return errorNum;
  }
};