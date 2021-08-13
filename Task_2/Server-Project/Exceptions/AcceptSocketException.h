#include <exception>

class AcceptSocketException: public std::exception {
private:
  int errorNum;

public:
  AcceptSocketException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket failed to accept connections";
  }
  int getError() {
    return errorNum;
  }
};
