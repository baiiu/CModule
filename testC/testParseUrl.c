//
// Created by baiiu on 2021/4/16.
//

#include "testParseUrl.h"
#include "common.h"
#include <regex.h>

void parseUrl() {

//    char *temp = "123test456test";
//    int result = atoi(temp);
//    printf("%d", result);

    char *p = "wwwcom:1935?streamid=#!::h=wwwcom,r=live/test123456";

    // 解析port
    char *col = strchr(p, ':');
    char *ques = strchr(p, '?');

    if (ques > col) {
        col++;
        unsigned int p2 = atoi(col);
        printf("port: %d\n", p2);
    }

    char *host = strstr(p, "h=");
    char *hostEnd = strchr(host, ',');
    host += 2;
    int hostLength = hostEnd - host;
    printf("host: %s, len: %d\n", host, hostLength);

    char *resource = strstr(p, "r=");
    char *rEnd = strchr(resource, ',');
    int resourceLength = rEnd - resource;
    printf("resource: %s, len: %d\n", resource, resourceLength);
}