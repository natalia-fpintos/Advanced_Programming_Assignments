#include "Comms.h"
#include "Exceptions/ConnectSocketException.h"
#include "Exceptions/SendException.h"

class Client: public Comms {
private:
  std::string getMessage();

public:
  Client();
  Client(int port);
  void connectSocket() throw (ConnectSocketException);
  void sendMsg() throw (SendException);
};
