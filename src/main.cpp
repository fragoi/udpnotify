#include "arguments.h"
#include "notifications.h"
#include "udpserver.h"
#include "protocol.h"

using namespace protocol;

int main(int argc, char **argv) {
  Arguments arguments = parseArgs(argc, argv);

  NotificationService notificationService;

  UdpServer server(arguments.port, [&](const char *msg) {
    Message message = parseMessage(msg);
    notificationService.notify(message);
  });

  server.run();
}
