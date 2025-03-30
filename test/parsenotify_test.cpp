#include <cassert>
#include <iostream>
#include <string>

#include "src/parsenotify.h"

using namespace std;
using namespace notifications;

static void bodyOnly() {
  Message message = parseMessage("hello");
  assert(message.body == "hello");
  assert(message.title == "");
  assert(message.urgency == NORMAL);
}

static void titleAndBody() {
  Message message = parseMessage("(title): hello");
  assert(message.body == "hello");
  assert(message.title == "title");
  assert(message.urgency == NORMAL);
}

static void lowUrgencyAndBody() {
  Message message = parseMessage("low: hello");
  assert(message.body == "hello");
  assert(message.title == "");
  assert(message.urgency == LOW);
}

static void lowUrgencyAndTitleAndBody() {
  Message message = parseMessage("low(title): hello");
  assert(message.body == "hello");
  assert(message.title == "title");
  assert(message.urgency == LOW);
}

static void normalUrgencyAndTitleAndBody() {
  Message message = parseMessage("normal(A nice title): hello world");
  assert(message.body == "hello world");
  assert(message.title == "A nice title");
  assert(message.urgency == NORMAL);
}

static void criticalUrgencyAndTitleAndBody() {
  Message message = parseMessage("critical(A nice title): hello world");
  assert(message.body == "hello world");
  assert(message.title == "A nice title");
  assert(message.urgency == CRITICAL);
}

int main() {
  bodyOnly();
  titleAndBody();
  lowUrgencyAndBody();
  lowUrgencyAndTitleAndBody();
  normalUrgencyAndTitleAndBody();
  criticalUrgencyAndTitleAndBody();

  cout << "OK" << endl;
}
