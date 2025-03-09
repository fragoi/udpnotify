#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <string>

namespace protocol {

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

  Message parseMessage(const string&);

}

#endif /* PROTOCOL_H_ */
