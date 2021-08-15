#include "Comms.h"
#include "Exceptions/ConnectSocketException.h"

class Client: public Comms {
public:
  Client();
  Client(int port);
  void connectSocket() throw (ConnectSocketException);
  void sendMsg() throw (SendException);
  void receiveData() throw (ReceiveException);
};
