#include <cassert>
#include <iostream>
#include <string>

#include "src/parsenotify.h"

using namespace std;
using namespace notifications;

static void bodyOnly() {
  Message message = parseMessage("hello");
  assert(message.body == "hello");
  assert(message.summary == "");
  assert(message.urgency == NORMAL);
}

static void summaryAndBody() {
  Message message = parseMessage("(summary): hello");
  assert(message.body == "hello");
  assert(message.summary == "summary");
  assert(message.urgency == NORMAL);
}

static void lowUrgencyAndBody() {
  Message message = parseMessage("low: hello");
  assert(message.body == "hello");
  assert(message.summary == "");
  assert(message.urgency == LOW);
}

static void lowUrgencyAndSummaryAndBody() {
  Message message = parseMessage("low(summary): hello");
  assert(message.body == "hello");
  assert(message.summary == "summary");
  assert(message.urgency == LOW);
}

static void normalUrgencyAndSummaryAndBody() {
  Message message = parseMessage("normal(A nice summary): hello world");
  assert(message.body == "hello world");
  assert(message.summary == "A nice summary");
  assert(message.urgency == NORMAL);
}

static void criticalUrgencyAndSummaryAndBody() {
  Message message = parseMessage("critical(A nice summary): hello world");
  assert(message.body == "hello world");
  assert(message.summary == "A nice summary");
  assert(message.urgency == CRITICAL);
}

int main() {
  bodyOnly();
  summaryAndBody();
  lowUrgencyAndBody();
  lowUrgencyAndSummaryAndBody();
  normalUrgencyAndSummaryAndBody();
  criticalUrgencyAndSummaryAndBody();

  cout << "OK" << endl;
}
