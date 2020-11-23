//
// Created by baiiu on 2020/11/23.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <zconf.h>
#include <netdb.h>
#include <net/if_var.h>
#include "testSocket.h"

#define SOCKET int
#define GetSocketError()   errno
#define closesocket(s)    close(s)

void testSocket() {

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1935);
    char *hostname = "test-tx-origin.meituan.com";
    addr.sin_addr.s_addr = inet_addr(hostname);


//    struct sockaddr_in addr;
//    memset(&addr, 0, sizeof(struct sockaddr_in));
//    addr.sin_family = AF_INET;
//    addr.sin_port = htons(8000);
//    addr.sin_addr.s_addr = inet_addr("10.28.226.35");


    if (addr.sin_addr.s_addr == INADDR_NONE) {
        struct hostent *host = gethostbyname(hostname);

        for (int i = 0; host->h_addr_list[i] != 0; ++i) {
            struct in_addr in;
            memcpy(&in, host->h_addr_list[i], sizeof(struct in_addr));
            printf("server ip: %s\n", inet_ntoa(in));
        }

        addr.sin_addr = *(struct in_addr *) host->h_addr;
    }

    SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (connect(fd, (const struct sockaddr *) &addr, sizeof(struct sockaddr)) < 0) {
        int err = GetSocketError();
        printf("error: %d, %s", err, strerror(err));

        closesocket(fd);
        return;
    }



    // can ping
//    printf("server ip: %s\n", inet_ntoa(addr.sin_addr));

    printf("connect");
    closesocket(fd);

}