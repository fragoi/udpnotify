#include <iostream>

#include "src/arguments.h"
#include "src/udpserver.h"

using namespace std;

int main(int argc, char **argv) {
  Arguments arguments = parseArgs(argc, argv);

  UdpServer server(arguments.port, [](const char *msg) {
    cout << msg << flush;
  });

  server.run();

  cout << "OK" << endl;
}
