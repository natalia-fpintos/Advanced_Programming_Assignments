#include <exception>

class ReceiveException: public std::exception {
public:
  virtual const char* what() const throw() {
    return "[ERROR] - There was an error receiving data";
  }
};