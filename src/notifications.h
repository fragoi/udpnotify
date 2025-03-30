#ifndef NOTIFICATIONS_H_
#define NOTIFICATIONS_H_

#include <string>

namespace notifications {

  using std::string;

  enum Urgency {
    LOW,
    NORMAL,
    CRITICAL
  };

  struct Message {
      string body;
      string title;
      Urgency urgency = NORMAL;
  };

  struct NotificationService {
      void notify(const Message&);
  };

}

#endif /* NOTIFICATIONS_H_ */
