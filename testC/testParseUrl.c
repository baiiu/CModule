//
// Created by baiiu on 2021/4/16.
//

#include "testParseUrl.h"
#include "common.h"
#include <regex.h>

static char *test() {

//    char *temp = "123test456test";
//    int result = atoi(temp);
//    printf("%d", result);

    char *p = "wwwcom:1935?streamid=#!::h=wwwcom,r=live/test123456";
    char *test = strchr(p, '-');
    if (test == NULL) {
        printf("test=======%s is NULL\n", test);
    }
    printf("test=======%s\n", test);

    // 解析port
    char *col = strchr(p, ':');
    char *ques = strchr(p, '?');

    if (ques > col) {
        col++;
        unsigned int p2 = atoi(col);
        printf("port: %d\n", p2);
    }

    char *end = p + strlen(p);

    char *host = strstr(p, "h=");
    host += 2;
    char *hostEnd = strchr(host, ',');
    if (!hostEnd) {
        hostEnd = end;
    }
    int hostLength = hostEnd - host;
    printf("host: %s, len: %d\n", host, hostLength);

    char *resource = strstr(p, "r=");
    resource += 2;
    char *rEnd = strchr(resource, ',');
    if (rEnd == NULL) {
        rEnd = end;
    }
    int resourceLength = rEnd - resource;
    printf("resource: %s, len: %d\n", resource, resourceLength);


//    char hostStr[hostLength + resourceLength + 2];
    char *hostStr = malloc((hostLength + resourceLength + 2) * sizeof(char));
    strncpy(hostStr, host, hostLength);
    printf("hostStr: %s\n", hostStr);


    strcat(hostStr, "/");
    printf("hostStr: %s\n", hostStr);

    strncat(hostStr, resource, resourceLength);
    hostStr[hostLength + resourceLength + 1] = '\0';
    printf("hostStr: %s\n", hostStr);

    return hostStr;
}

void test2() {
    int port = 1935;
    char portStr[6];
    int length = sprintf(portStr, "%d", port);
    printf("%s, %d, %lu", portStr, length, strlen(portStr));
}

void test3(AVal *aval) {
//    char *url = "https://www.baidu.com:443?test=123";
    char url[100];
    "https://www.baidu.com:443?test=123";
    strcpy(url, "https://www.baidu.com:443?test=123");

    char *p = strstr(url, "://");
    aval->av_val = p;
    aval->av_len = strlen(p);
}

void parseUrl() {
//    char *s = test();
//    printf("s: %s\n", s);
//    free(s);
//    s = NULL;

//    test2();

    AVal aVal;
    test3(&aVal);
    printf("avl: %s, %d", aVal.av_val, aVal.av_len);

}