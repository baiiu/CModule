//
// Created by baiiu on 2021/6/23.
//

#include <netdb.h>
#include <errno.h>
#include "testDNS.h"
#include "common.h"
#include <zconf.h>
#include <dns_util.h>

#define SOCKET int

void connectIt(struct addrinfo *ai) {
    printf("ai_family: %d, ai_socktype: %d, ai_protocol: %d\n", ai->ai_family, ai->ai_socktype, ai->ai_protocol);
//    SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKET fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);

    if (fd == -1) {
        printf("socket create error");
        return;
    }

    printf("ai_addr, %p, sa_data: %s\n", ai->ai_addr, ai->ai_addr->sa_data);
    if (connect(fd, ai->ai_addr, ai->ai_addrlen) < 0) {
        int err = errno;
        printf("error: %d, %s", err, strerror(err));

        close(fd);
        return;
    }

    printf("\nconnected\n");
    close(fd);
}

void parseDNS() {
    struct addrinfo hints = {0}, *ai, *cur_ai;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    char *hostname = "beauty-tx-flv.meituan.net";
//    char *hostname = "119.167.134.126";
    char portstr[10];
    int port = 443;
    snprintf(portstr, sizeof(portstr), "%d", port);

    int64_t dns_starttime = av_gettime_relative();
    int ret = getaddrinfo(hostname, portstr, &hints, &ai);
    int64_t dnsCost = (av_gettime_relative() - dns_starttime) / 1000;
    printf("dnsCost: %lld\n", dnsCost);

    printf("ret: %d\n", ret);
    printf("parseDNS#ai_family: %d, ai_socktype: %d, ai_protocol: %d, ai_addrlen: %d\n", ai->ai_family, ai->ai_socktype,
           ai->ai_protocol, ai->ai_addrlen);

    // 打印ip地址
    char ipbuf[16];
    for (cur_ai = ai; cur_ai != NULL; cur_ai = cur_ai->ai_next) {
        struct sockaddr_in *addr = (struct sockaddr_in *) cur_ai->ai_addr;
        printf("inet_ntop: %s\n", inet_ntop(AF_INET, &addr->sin_addr, ipbuf, 16));

        struct in_addr temp = ((struct sockaddr_in *) cur_ai->ai_addr)->sin_addr;
        printf("inet_ntoa: %s\n", inet_ntoa(temp));
    }

    freeaddrinfo(ai);
    printf("\ndnsCost: %lld\n", dnsCost);

//    cur_ai = ai;
//    connectIt(cur_ai);
}


void testWrongDNS() {
    struct addrinfo hints = {0}, *ai, *cur_ai;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    char *hostname = "beauty-tx-flv.meituan.net";
//    char *hostname = "221.204.181.64";
    char portstr[10];
    int port = 443;
    snprintf(portstr, sizeof(portstr), "%d", port);

    int64_t dns_starttime = av_gettime_relative();
    int ret = getaddrinfo(hostname, portstr, &hints, &ai);
    int64_t dnsCost = (av_gettime_relative() - dns_starttime) / 1000;
    printf("dnsCost: %lld\n", dnsCost);

    printf("ret: %d, error: %s \n", ret, gai_strerror(ret));
    printf("parseDNS#ai_family: %d, ai_socktype: %d, ai_protocol: %d, ai_addrlen: %d\n", ai->ai_family, ai->ai_socktype,
           ai->ai_protocol, ai->ai_addrlen);

    // 打印ip地址
    char ipbuf[16];
    for (cur_ai = ai; cur_ai != NULL; cur_ai = cur_ai->ai_next) {
        struct sockaddr_in *addr = (struct sockaddr_in *) cur_ai->ai_addr;
        printf("inet_ntop: %s\n", inet_ntop(AF_INET, &addr->sin_addr, ipbuf, 16));

        struct in_addr temp = ((struct sockaddr_in *) cur_ai->ai_addr)->sin_addr;
        printf("inet_ntoa: %s\n", inet_ntoa(temp));
    }

    freeaddrinfo(ai);
    printf("\ndnsCost: %lld\n", dnsCost);
}

void testFreeDNS() {
    struct addrinfo hints = {0}, *res;
    hints.ai_family = AF_INET; // AF_INET表示ipv4，只发type A请求

    int ret = getaddrinfo("1.1.com", NULL, &hints, &res);

    printf("%s: error: %d, msg: %s, res: %p", __func__, ret, gai_strerror(ret), res);

    freeaddrinfo(res);

    const char *name = NULL;
    if (!name) {
        printf("\n123");
    }
}

void testDNS() {
//    parseDNS();
//    testWrongDNS();
    testFreeDNS();
}