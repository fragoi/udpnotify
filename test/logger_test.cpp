#include <iostream>

#include "src/logger.h"

using namespace std;

static void withPrefix() {
  Logger logger("[Test]");
  logger.info() << "withPrefix" << endl;
}

static void withoutPrefix() {
  Logger logger;
  logger.info() << "withoutPrefix" << endl;
}

int main() {
  withPrefix();
  withoutPrefix();

  cout << "OK" << endl;
}
