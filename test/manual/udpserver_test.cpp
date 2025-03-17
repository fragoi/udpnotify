#include <iostream>

#include "src/udpserver.h"

using namespace std;

int main() {
  UdpServer server(50000, [](const char*) {
  });

  cout << "OK" << endl;
}
