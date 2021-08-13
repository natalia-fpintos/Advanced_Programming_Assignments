#include <exception>

class ListenSocketException: public std::exception {
private:
  int errorNum;

public:
  ListenSocketException(int errorNum) : errorNum(errorNum) {}
  virtual const char* what() const throw() {
    return "[ERROR] - Socket could not listen on port";
  }
  int getError() {
    return errorNum;
  }
};