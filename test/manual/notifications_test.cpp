#include <iostream>

#include "src/notifications.h"

using namespace std;
using namespace protocol;

static void messageWithBody() {
  Message message = {
      .body = "hello"
  };

  NotificationService().notify(message);
}

static void messageWithBodyAndTitle() {
  Message message = {
      .body = "hello",
      .title = "Title"
  };

  NotificationService().notify(message);
}

int main() {
  messageWithBody();
  messageWithBodyAndTitle();

  cout << "OK" << endl;
}
