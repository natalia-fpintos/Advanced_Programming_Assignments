#include "Comms.h"
#include "Exceptions/ConnectSocketException.h"

class Client: public Comms {
private:
  std::string sendMsg() throw (SendException);
  void receiveData(char* buffer, int size) throw (ReceiveException);
public:
  Client();
  Client(int port);
  void connectSocket() throw (ConnectSocketException);
  void startChat() throw(class StartChatException);
};
