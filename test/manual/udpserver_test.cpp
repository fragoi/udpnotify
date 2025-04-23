#include <iostream>
#include <cstring>

#include "src/arguments.h"
#include "src/udpserver.h"

using namespace std;

int main(int argc, char **argv) {
  Arguments arguments = parseArgs(argc, argv);

  UdpServer server(arguments.port, [](const char *msg, const char *from) {
    if (strcmp(msg, "error") == 0) {
      throw std::runtime_error("error");
    }
    cout << from << ": " << msg << endl;
  });

  server.run();

  cout << "OK" << endl;
}
