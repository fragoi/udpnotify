#ifndef NOTIFICATIONS_H_
#define NOTIFICATIONS_H_

#include "protocol.h"

class NotificationService {
    using Message = protocol::Message;

  public:
    void notify(const Message&);
};

#endif /* NOTIFICATIONS_H_ */
