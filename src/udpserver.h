#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include <functional>

class UdpServer {
    friend class UdpServerPrivate;

    using Callback = std::function<void(const char *)>;

    int port;
    Callback cb;

    int fd = -1;

  public:
    UdpServer(int port, Callback cb);
    ~UdpServer();

    void run();
};

#endif /* UDPSERVER_H_ */
