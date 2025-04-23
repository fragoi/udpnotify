#include <regex>

#include "parsenotify.h"
#include "logger.h"

using namespace std;
using namespace notifications;

static const Logger notifyLogger("[Notify]");

static Urgency parseUrgency(const string &s) {
  if (s == "low") {
    return LOW;
  } else if (s == "critical") {
    return CRITICAL;
  } else {
    return NORMAL;
  }
}

static string parseSummary(const string &s) {
  return s.empty() ? s : s.substr(1, s.length() - 2);
}

Message notifications::parseMessage(const string &msg) {
  regex re("^([[:alpha:]]+)?([(].+[)])?: ");
  smatch m;
  Message message;

  if (regex_search(msg, m, re)) {
    message.urgency = parseUrgency(m[1]);
    message.summary = parseSummary(m[2]);
    message.body = msg.substr(m.length());
  } else {
    message.body = msg;
  }

  return message;
}

static string prepend(const string &s, const string &v) {
  if (s.empty()) {
    return v;
  }
  if (v.empty()) {
    return s;
  }
  return v + ": " + s;
}

void Notify::operator()(const char *msg, const char *from) {
  try {
    Message message = parseMessage(msg);
    message.summary = prepend(message.summary, from);
    service.notify(message);
  } catch (const exception &e) {
    LOGGER_ERROR(notifyLogger) << e.what() << endl;
  }
}
