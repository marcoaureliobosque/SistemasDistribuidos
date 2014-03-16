// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Agenda.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::tutorial;

class AgendaHandler : virtual public AgendaIf {
 public:
  AgendaHandler() {
    // Your initialization goes here
  }

  void getDatabase(std::string& _return) {
    // Your implementation goes here
    printf("getDatabase\n");
  }

  void insert(std::string& _return, const std::string& name, const std::string& fone, const Int op) {
    // Your implementation goes here
    printf("insert\n");
  }

  void search(std::string& _return, const std::string& name) {
    // Your implementation goes here
    printf("search\n");
  }

  void remove(std::string& _return, const std::string& name) {
    // Your implementation goes here
    printf("remove\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<AgendaHandler> handler(new AgendaHandler());
  shared_ptr<TProcessor> processor(new AgendaProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
