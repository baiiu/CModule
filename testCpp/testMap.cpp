//
// Created by ByteDance on 2025/9/15.
//

#include "testMap.h"

void testMap() {

    std::unordered_map<std::string, int> map = {
            {"a", 1},
            {"b", 2},
            {"c", 3},
            {"d", 4},
            {"e", 5},
            {"f", 6},
            {"g", 7},
            {"h", 8},
            {"i", 9},
            {"j", 10},
            {"k", 11},
    };
    map["s"] += 1;
    map["s"] += 2;

    // 拷贝赋值
    std::unordered_map<std::string, int> map2 = map;
    map2["m"] = 12;

    for (auto it = map.begin(); it != map.end();) {
        if (it->second % 2 == 0) {
            it = map.erase(it);
            continue;
        }

        ++it;
    }


    printMap(map);
    printMap(map2);
}

void printMap(std::unordered_map<std::string, int> &map) {
    for (auto &it: map) {
        cout << it.first << ", " << it.second << endl;
    }
    cout << "==================" << map.size() << endl;
}