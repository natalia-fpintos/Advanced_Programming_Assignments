#include "Comms.h"
#include "Exceptions/ConnectSocketException.h"

class Client: public Comms {
public:
  Client();
  Client(int port);
  void connectSocket() throw (ConnectSocketException);
  void sendMsg() throw (SendException);
  char* receiveData() throw (ReceiveException);
  void startChat() throw(class StartChatException);
};
