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
#include <net/if.h>
#include <sys/ioctl.h>
#include "testSocket.h"

#define SOCKET int
#define GetSocketError()   errno
#define closesocket(s)    close(s)

void connect0(struct sockaddr_in addr) {

    SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (connect(fd, (const struct sockaddr *) &addr, sizeof(struct sockaddr)) < 0) {
        int err = GetSocketError();
        printf("error: %d, %s", err, strerror(err));

        closesocket(fd);
        return;
    }

    printf("\nconnect\n");


    socklen_t len;


    TLink tLink;
    memset(&tLink, 0, sizeof(TLink));

    // server ip
    getpeername(fd, (struct sockaddr *) &addr, &len);
    printf("socklen_t: %d\n", len);
    char buf[16] = "";
    const char *serverip = inet_ntop(AF_INET, &(addr.sin_addr), buf, sizeof(buf));
    int serverport = ntohs(addr.sin_port);
    printf("server ip: %s\n", serverip);
    printf("server port: %d\n", serverport);

    AVal serverIP;
    memset(&serverIP, 0, sizeof(AVal));
    serverIP.av_val = serverip;
    serverIP.av_len = strlen(serverip);
    printf("AVal#serverIP: %s,%d\n", serverIP.av_val, serverIP.av_len);



    // local ip
    getsockname(fd, (struct sockaddr *) &addr, &len);
    printf("socklen_t: %d\n", len);
    const char *localip = inet_ntop(AF_INET, &(addr.sin_addr), buf, sizeof(buf));
    int port = ntohs(addr.sin_port);
    printf("local ip: %s\n", localip);
    printf("local port: %d\n", port);

    AVal localIP;
    memset(&localIP, 0, sizeof(AVal));
    localIP.av_len = strlen(localip);
    localIP.av_val = localip;
    printf("AVal#localIP: %s,%d\n", localIP.av_val, localIP.av_len);

    closesocket(fd);
}

void connect1(struct sockaddr_in *addr) {

    SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (connect(fd, (const struct sockaddr *) addr, sizeof(struct sockaddr)) < 0) {
        int err = GetSocketError();
        printf("error: %d, %s", err, strerror(err));

        closesocket(fd);
        return;
    }

    printf("\nconnect\n");


    socklen_t len;


    TLink tLink;
    memset(&tLink, 0, sizeof(TLink));

    // server ip
    getpeername(fd, (struct sockaddr *) addr, &len);
    printf("socklen_t: %d\n", len);
    char buf[16] = "";
    const char *serverip = inet_ntop(AF_INET, &addr->sin_addr, buf, sizeof(buf));
    int serverport = ntohs(addr->sin_port);
    printf("server ip: %s\n", serverip);
    printf("server port: %d\n", serverport);

    AVal serverIP;
    memset(&serverIP, 0, sizeof(AVal));
    serverIP.av_val = serverip;
    serverIP.av_len = strlen(serverip);
    printf("AVal#serverIP: %s,%d\n", serverIP.av_val, serverIP.av_len);



    // local ip
    getsockname(fd, (struct sockaddr *) addr, &len);
    printf("socklen_t: %d\n", len);
    const char *localip = inet_ntop(AF_INET, &addr->sin_addr, buf, sizeof(buf));
    int port = ntohs(addr->sin_port);
    printf("local ip: %s\n", localip);
    printf("local port: %d\n", port);

    AVal localIP;
    memset(&localIP, 0, sizeof(AVal));
    localIP.av_len = strlen(localip);
    localIP.av_val = localip;
    printf("AVal#localIP: %s,%d\n", localIP.av_val, localIP.av_len);

    closesocket(fd);
}

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
        printf("s_addr is INADDR_NONE\n");

        struct hostent *host = gethostbyname(hostname);

        printf("gethostbyname: %s\n", host->h_name);


        for (int i = 0; host->h_addr_list[i] != 0; ++i) {
            struct in_addr in;
            memcpy(&in, host->h_addr_list[i], sizeof(struct in_addr));
//            printf("server ip: %s\n", inet_ntoa(in));
        }

        addr.sin_addr = *(struct in_addr *) host->h_addr;
    }

//    connect0(addr);
    connect1(&addr);
}