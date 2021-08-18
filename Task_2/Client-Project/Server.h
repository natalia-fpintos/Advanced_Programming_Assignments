#include "Comms.h"
#include "Exceptions/BindSocketException.h"
#include "Exceptions/ListenSocketException.h"
#include "Exceptions/AcceptSocketException.h"

class Server: public Comms {
private:
  int clientSocketRef;
  std::string sendMsg() throw (SendException);
  void receiveData(char* buffer, int size) throw (ReceiveException);
public:
  Server();
  Server(int port);
  void bindSocket() throw (BindSocketException);
  void listenSocket() throw (ListenSocketException);
  void acceptSocket() throw (AcceptSocketException);
  void startChat() throw(class StartChatException);
};
