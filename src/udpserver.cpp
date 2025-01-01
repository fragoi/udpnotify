#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "udpserver.h"
#include "exceptions.h"
#include "logger.h"

#define BUFFER_LENGTH 512

static const Logger logger("[UdpServer]");

static int createSocket() {
  int fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (fd < 0) {
    throw ErrnoException("Error creating socket");
  }
  return fd;
}

static void bindPort(int fd, int port) {
  sockaddr_in bindAddr;
  bindAddr.sin_addr.s_addr = INADDR_ANY;
  bindAddr.sin_family = AF_INET;
  bindAddr.sin_port = htons(port);
  if (bind(fd, (sockaddr*) &bindAddr, sizeof(bindAddr)) < 0) {
    throw ErrnoException("Error binding socket");
  }
}

UdpServer::UdpServer(int port, Callback cb) :
    port(port),
    cb(cb) {
  fd = createSocket();
  bindPort(fd, port);
  LOGGER_INFO(logger) << "Listening on port: " << port << std::endl;
}

UdpServer::~UdpServer() {
  if (fd >= 0) {
    shutdown(fd, 0);
    close(fd);
  }
  LOGGER_INFO(logger) << "Socket closed" << std::endl;
}

void UdpServer::run() {
  int nread;
  char buffer[BUFFER_LENGTH + 1];
  while ((nread = recv(fd, buffer, BUFFER_LENGTH, 0)) > 0) {
    buffer[nread] = '\0';
    cb(buffer);
  }
  if (nread < 0) {
    throw ErrnoException("Error reading from socket");
  }
}
