#include <exception>

class ConnectSocketException: public std::exception {
private:
  int errorNum;

public:
  ConnectSocketException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket failed to connect";
  }
  int getError() {
    return errorNum;
  }
};
