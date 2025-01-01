#include <argp.h>
#include <stdlib.h>
#include <stdexcept>
#include <asm-generic/errno-base.h>
#include <cstring>

#include "arguments.h"

using std::invalid_argument;
using std::runtime_error;

static int parseInt(char *arg, argp_state *state) {
  char *end;
  int i = strtol(arg, &end, 10);
  if (*end) {
    argp_error(state, "Error parsing number %s", arg);
    throw invalid_argument(arg);
  }
  return i;
}

static error_t parseOpt(int key, char *arg, argp_state *state) {
  Arguments *arguments = (Arguments*) state->input;
  try {
    switch (key) {
      case 'p':
        arguments->port = parseInt(arg, state);
        break;
      default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
  } catch (const invalid_argument &e) {
    return EINVAL;
  }
}

Arguments parseArgs(int argc, char **argv, bool no_exit) {
  argp_option options[] = {
      { "port", 'p', "port", 0, "the port to listen for" },
      { 0 }
  };

  argp argp = {
      options,
      parseOpt
  };

  int flags = 0;
  if (no_exit) {
    flags |= ARGP_NO_EXIT;
  }

  Arguments arguments;
  error_t error = argp_parse(&argp, argc, argv, flags, nullptr, &arguments);
  if (error) {
    throw runtime_error(strerror(error));
  }
  return arguments;
}
