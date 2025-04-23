#ifndef PARSENOTIFY_H_
#define PARSENOTIFY_H_

#include "notifications.h"

namespace notifications {

  Message parseMessage(const string&);

  class Notify {
      NotificationService service;

    public:
      void operator()(const char*, const char*);
  };

}

#endif /* PARSENOTIFY_H_ */
