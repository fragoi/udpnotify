#include <iostream>
#include <unistd.h>

#include "src/parsenotify.h"

using namespace std;
using namespace notifications;

static const char *SOME_IP = "192.168.18.42";

static void simpleMessageWithEmptySender() {
  Notify()("hello", "");
}

static void simpleMessageWithSender() {
  Notify()("hello", SOME_IP);
}

static void messageWithSummary() {
  Notify()("normal(A nice summary): hello", "");
}

static void messageWithSummaryAndSender() {
  Notify()("normal(A nice summary): hello", SOME_IP);
}

int main() {
  simpleMessageWithEmptySender();
  simpleMessageWithSender();
  messageWithSummary();
//  messageWithSummaryAndSender();
  cout << "OK" << endl;
}
