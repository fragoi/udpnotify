#include <cassert>
#include <iostream>
#include <exception>

#include "src/arguments.h"

using namespace std;

static void test_port_valid() {
  int argc = 3;
  char *argv[argc] = {
      (char*) "test",
      (char*) "-p",
      (char*) "8080"
  };
  Arguments args = parseArgs(argc, argv);
  assert(args.port == 8080);
}

static void test_port_invalid() {
  int argc = 3;
  char *argv[argc] = {
      (char*) "test",
      (char*) "-p",
      (char*) "8x80"
  };
  try {
    parseArgs(argc, argv, true);
    assert(false);
  } catch (const exception &e) {
    assert(true);
  }
}

static void test_port_novalue() {
  int argc = 2;
  char *argv[argc] = {
      (char*) "test",
      (char*) "-p"
  };
  try {
    parseArgs(argc, argv, true);
    assert(false);
  } catch (const exception &e) {
    assert(true);
  }
}

static void test_port_default() {
  int argc = 1;
  char *argv[argc] = {
      (char*) "test"
  };
  Arguments args = parseArgs(argc, argv);
  assert(args.port == 50000);
}

static void test_port_long() {
  int argc = 3;
  char *argv[argc] = {
      (char*) "test",
      (char*) "--port",
      (char*) "8080"
  };
  Arguments args = parseArgs(argc, argv);
  assert(args.port == 8080);
}

int main() {
  test_port_valid();
  test_port_invalid();
  test_port_novalue();
  test_port_default();
  test_port_long();

  cout << "OK" << endl;
}
