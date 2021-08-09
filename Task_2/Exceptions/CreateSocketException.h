#include <exception>

using namespace std;

class CreateSocketException: public exception {
public:
  virtual const char* what() const throw() {
    return "[ERROR] - Could not create the socket";
  }
};
