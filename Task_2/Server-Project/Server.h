#include "Comms.h"
#include "Exceptions/BindSocketException.h"
#include "Exceptions/ListenSocketException.h"
#include "Exceptions/AcceptSocketException.h"

class Server: public Comms {
public:
  Server();
  Server(int port);
  void bindSocket() throw (BindSocketException);
  void listenSocket() throw (ListenSocketException);
  void acceptSocket() throw (AcceptSocketException);
};
