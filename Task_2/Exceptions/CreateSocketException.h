#include <exception>

class CreateSocketException: public std::exception {
public:
  virtual const char* what() const throw() {
    return "[ERROR] - Could not create the socket";
  }
};
