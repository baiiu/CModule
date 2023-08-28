//
// Created by ByteDance on 2023/5/29.
//

#include "testSem.h"
#include "semaphore.h"

// 4 个售票员卖 100 张票
sem_t mySem;
int ticket_sum = 10;

void *sell_ticket(void *arg) {
//    cout << "当前线程ID：" << pthread_self() << endl;

    int flag;
    for (int i = 0; i < 10; ++i) {
        flag = sem_wait(&mySem);
        cout << "flag: " << flag << endl;

        if (flag == 0) {
            if (ticket_sum > 0) {
                cout << pthread_self() << " 卖第 " << ticket_sum << " 张票\n" << endl;
                ticket_sum--;
            }
            sem_post(&mySem);
        }
    }

    return nullptr;
};

void testSem() {
    int ret = sem_init(&mySem, 0, 1);
    cout << "ret: " << ret << endl;


    //创建 4 个线程
    pthread_t tids[4];
    for (int i = 0; i < 4; ++i) {
        pthread_create(&tids[i], nullptr, &sell_ticket, nullptr);
    }

    sleep(10);

    void *ans;
    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], &ans);
    }
    sem_destroy(&mySem);
}