#include <cerrno>
#include <cstring>
#include <string>

#include "exceptions.h"

using namespace std;

static string buildMsg(const char *base) noexcept {
  const char *serr = strerror(errno);
  string msg;
  if (base) {
    msg += base;
    msg += ": ";
  }
  msg += serr;
  return msg;
}

ErrnoException::ErrnoException(const char *baseMsg) noexcept :
    runtime_error(buildMsg(baseMsg)) {
}
