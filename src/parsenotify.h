#ifndef PARSENOTIFY_H_
#define PARSENOTIFY_H_

#include "notifications.h"

namespace protocol {

  using namespace notifications;

  Message parseMessage(const string&);

}

#endif /* PARSENOTIFY_H_ */
