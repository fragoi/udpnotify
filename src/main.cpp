#include "arguments.h"
#include "notifications.h"
#include "udpserver.h"
#include "parsenotify.h"

using namespace notifications;

int main(int argc, char **argv) {
  Arguments arguments = parseArgs(argc, argv);

  NotificationService notificationService;

  UdpServer server(arguments.port, [&](const char *msg) {
    Message message = parseMessage(msg);
    notificationService.notify(message);
  });

  server.run();
}
