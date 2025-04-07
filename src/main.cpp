#include "arguments.h"
#include "udpserver.h"
#include "parsenotify.h"

using namespace notifications;

int main(int argc, char **argv) {
  Arguments arguments = parseArgs(argc, argv);

  UdpServer server(arguments.port, Notify());

  server.run();
}
