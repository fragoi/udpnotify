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

static void messageWithBodyAndTitle() {
  Message message = {
      .body = "hello",
      .summary = "Title"
  };

  NotificationService().notify(message);
}

static void messageWithBodyAndTitleAndUrgency() {
  Message message = {
      .body = "hello",
      .summary = "Important",
      .urgency = CRITICAL
  };

  NotificationService().notify(message);
}

int main() {
  messageWithBody();
  messageWithBodyAndTitle();
  messageWithBodyAndTitleAndUrgency();

  cout << "OK" << endl;
}
