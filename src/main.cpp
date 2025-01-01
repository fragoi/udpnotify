#include "arguments.h"
#include "notifications.h"
#include "udpserver.h"

int main(int argc, char **argv) {
  Arguments arguments = parseArgs(argc, argv);

  NotificationService notificationService;

  UdpServer server(arguments.port, [&](const char *msg) {
    notificationService.notify(msg);
  });

  server.run();
}
