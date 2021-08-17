#pragma once

#include <exception>
#include <string>
#include <iostream>

class ExceptionWithMessage: public std::exception {
protected:
  int errorNum;

public:
  typedef std::string (*logNameFP)();
  ExceptionWithMessage() : errorNum(0) {};
  ExceptionWithMessage(int errorNum) : errorNum(errorNum) {};
  virtual const char* what() const throw() = 0;
  void logErrorMsg(logNameFP getLogName) {
    std::cout << getLogName() << " - " << what();

    if (getError() != 0) {
      std::cout << ". Error number: " << getError();
    }

    std::cout << std::endl;
  }
  int getError() {
    return errorNum;
  }
};
