#include "Comms.h"
#include "Exceptions/BindSocketException.h"

class Server: public Comms {
public:
  Server();
  Server(int port);
  void bindSocket() throw (BindSocketException);
};
