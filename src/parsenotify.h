#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "notifications.h"

namespace protocol {

  using namespace notifications;

  Message parseMessage(const string&);

}

#endif /* PROTOCOL_H_ */
