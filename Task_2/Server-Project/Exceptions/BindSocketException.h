#include <exception>

class BindSocketException: public std::exception {
private:
  int errorNum;

public:
  BindSocketException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket failed to bind";
  }
  int getError() {
    return errorNum;
  }
};
