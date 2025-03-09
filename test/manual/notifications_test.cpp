#include <iostream>

#include "src/notifications.h"

using namespace std;
using namespace protocol;

int main() {
  Message message = {
      .body = "hello"
  };

  NotificationService service;
  service.notify(message);

  cout << "OK" << endl;
}
