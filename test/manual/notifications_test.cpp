#include <iostream>

#include "src/notifications.h"

using namespace std;
using namespace notifications;

static void messageWithBody() {
  Message message = {
      .body = "hello"
  };

  NotificationService().notify(message);
}

static void messageWithBodyAndSummary() {
  Message message = {
      .body = "hello",
      .summary = "Summary"
  };

  NotificationService().notify(message);
}

static void messageWithBodyAndSummaryAndUrgency() {
  Message message = {
      .body = "hello",
      .summary = "Important",
      .urgency = CRITICAL
  };

  NotificationService().notify(message);
}

int main() {
  messageWithBody();
  messageWithBodyAndSummary();
  messageWithBodyAndSummaryAndUrgency();

  cout << "OK" << endl;
}
