#include "Server.h"

int main () {
  try {
    Server *server = new Server();
    server->createSocket(Comms::TCP);
    server->bindSocket();
  } catch (SetSocketOptionsException exception) {
    std::cout << exception.what() << ": Error code " << exception.getError() << std::endl;
  }
}
