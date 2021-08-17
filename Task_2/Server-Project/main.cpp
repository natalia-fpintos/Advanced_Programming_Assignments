//#define SERVER
#define CLIENT

#ifdef SERVER
#include "Server.h"
#endif

#ifdef CLIENT
#include "Client.h"
#endif

#ifdef SERVER
std::string logServer() {
  return "[SERVER]";
}
#endif

#ifdef CLIENT
std::string logClient() {
  return "[CLIENT]";
}
#endif


int main () {
  #ifdef SERVER
  try {
    Server* server = new Server();
    server->createSocket(Comms::TCP);
    server->bindSocket();
    server->listenSocket();
    server->acceptSocket();
    server->startChat();
  } catch (CreateSocketException& e) {
    e.logErrorMsg(logServer);
  } catch (BindSocketException& e) {
    e.logErrorMsg(logServer);
  } catch (ListenSocketException& e) {
    e.logErrorMsg(logServer);
  } catch (AcceptSocketException& e) {
    e.logErrorMsg(logServer);
  } catch (SendException& e) {
    e.logErrorMsg(logServer);
  } catch (ReceiveException& e) {
    e.logErrorMsg(logServer);
  } catch (...) {
    std::cout << logServer() << " - [ERROR] - There was an unspecified exception";
  }
  #endif

  #ifdef CLIENT
  try {
    Client* client = new Client();
    client->createSocket(Comms::TCP);
    client->connectSocket();
    client->startChat();
  } catch (CreateSocketException& e) {
    e.logErrorMsg(logClient);
  } catch (ConnectSocketException& e) {
    e.logErrorMsg(logClient);
  } catch (SendException& e) {
    e.logErrorMsg(logClient);
  } catch (ReceiveException& e) {
    e.logErrorMsg(logClient);
  } catch (...) {
    std::cout << logClient() << " - [ERROR] - There was an unspecified exception";
  }
  #endif

}
