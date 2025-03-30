#include <regex>

#include "parsenotify.h"

using namespace std;
using namespace notifications;

static Urgency parseUrgency(const string &s) {
  if (s == "low") {
    return LOW;
  } else if (s == "critical") {
    return CRITICAL;
  } else {
    return NORMAL;
  }
}

static string parseTitle(const string &s) {
  return s.empty() ? s : s.substr(1, s.length() - 2);
}

Message notifications::parseMessage(const string &msg) {
  regex re("^([[:alpha:]]+)?([(].+[)])?: ");
  smatch m;
  Message message;

  if (regex_search(msg, m, re)) {
    message.urgency = parseUrgency(m[1]);
    message.title = parseTitle(m[2]);
    message.body = msg.substr(m.length());
  } else {
    message.body = msg;
  }

  return message;
}
