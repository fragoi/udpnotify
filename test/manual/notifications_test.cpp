#include <iostream>

#include "src/notifications.h"

using namespace std;

int main() {
  NotificationService service;
  service.notify("hello");

  cout << "OK" << endl;
}
