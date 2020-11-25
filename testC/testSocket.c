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

void printIP(SOCKET fd) {

    TLink tLink;
    memset(&tLink, 0, sizeof(TLink));

    char buf[30] = "";

    // peer ip
    struct sockaddr_in peerAddr;
    socklen_t peerLen = 100;
    memset(buf, 0, sizeof(buf));
    bzero(&peerAddr, sizeof(peerAddr));
    getpeername(fd, (struct sockaddr *) &peerAddr, &peerLen);
    const char *constServerIP = inet_ntop(AF_INET, &(peerAddr.sin_addr), buf, sizeof(buf));
    char serverip[strlen(constServerIP) + 1];
    strcpy(serverip, constServerIP);
    int serverport = ntohs(peerAddr.sin_port);
    printf("constServerIP: %s,  serverport: %d\n", constServerIP, serverport);

    AVal serverIP;
    memset(&serverIP, 0, sizeof(AVal));
    serverIP.av_val = serverip;
    serverIP.av_len = strlen(serverip);
    tLink.server_ip = serverIP;
    printf("AVal#serverIP: %s,%d\n", tLink.server_ip.av_val, tLink.server_ip.av_len);

    // local ip
    struct sockaddr_in localAddr;
    socklen_t localLen = 100;
    memset(buf, 0, sizeof(buf));
    bzero(&localAddr, sizeof(localAddr));
    getsockname(fd, (struct sockaddr *) &localAddr, &localLen);
    const char *constLocalIP = inet_ntop(AF_INET, &localAddr.sin_addr, buf, sizeof(buf));
    int localPort = ntohs(localAddr.sin_port);
    char localip[strlen(constLocalIP) + 1];
    strcpy(localip, constLocalIP);
    printf("constLocalIP: %s, localPort: %d\n", constLocalIP, localPort);

    AVal localIP;
    memset(&localIP, 0, sizeof(AVal));
    localIP.av_len = strlen(localip);
    localIP.av_val = localip;
    tLink.local_ip = localIP;
    printf("AVal#localIP: %s,%d\n", tLink.local_ip.av_val, tLink.local_ip.av_len);
}

void connect0(struct sockaddr_in addr) {

    SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (connect(fd, (const struct sockaddr *) &addr, sizeof(struct sockaddr)) < 0) {
        int err = GetSocketError();
        printf("error: %d, %s", err, strerror(err));

        closesocket(fd);
        return;
    }

    printf("\nconnect\n\n");

    printIP(fd);
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

    printIP(fd);

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

    connect0(addr);
//    connect1(&addr);
}

void connect2(struct addrinfo *ai, unsigned short port) {
    SOCKET fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);

    if (ai->ai_family == AF_INET6) {
        struct sockaddr_in6 *in6 = (struct sockaddr_in6 *) ai->ai_addr;
        in6->sin6_port = htons(port);
    }

    if (connect(fd, ai->ai_addr, ai->ai_addrlen) < 0) {
        int err = GetSocketError();
        printf("error: %d, %s", err, strerror(err));

        closesocket(fd);
        return;
    }


    printf("\nconnect\n");

    printIP(fd);

    closesocket(fd);
}

void testSocket2() {
    struct addrinfo hints = {0}, *ai, *cur_ai;
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_DEFAULT;
    int port = 1935;
    char *hostname = "live-origin.test.mtyuncdn.com";

    // do not use gethostbyname which case crash, use this program
    char portstr[10];
    snprintf(portstr, sizeof(portstr), "%d", port);
    int addrret = getaddrinfo(hostname, portstr, &hints, &ai);
    printf("addrret: %d\n", addrret);

    if (addrret != 0) {
        printf("Problem accessing the DNS. (addr: %s)", hostname);
    }
    cur_ai = ai;

    connect2(cur_ai, port);
}


int add_addr_info(struct addrinfo *hints, struct addrinfo **ai, char *hostname, int port) {

    printf("add_addr_info: hostname: %s, port: %d\n", hostname, port);

    char portstr[10];
    snprintf(portstr, sizeof(portstr), "%d", port);
    int addrret = getaddrinfo(hostname, portstr, hints, ai);
    printf("addrret: %d\n", addrret);

    if (addrret != 0) {
        printf("Problem accessing the DNS. (addr: %s)\n", hostname);
        return 0;
    }

    return 1;
}


void testSocket3() {
    struct addrinfo hints = {0}, *ai, *cur_ai;
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_ALL;
    char *hostname = "test-tx-origin.meituan.com";
    unsigned short port = 1935;

    if (!add_addr_info(&hints, &ai, hostname, port)) {
        printf("sth error");
        return;
    }

    cur_ai = ai;
    connect2(cur_ai, port);

}