#include <mutex>
#include <iostream>
#include <thread>

using namespace std;

int countnum = 0;
mutex m;

void add() {
    m.lock();
    countnum++;
    m.unlock();
}

void print1() {
    cout << "print1\n";
}

void print2() {
    cout << "print2\n";
}

int main() {
    thread t1(print1);
    thread t2(print2);
    // join函数目的是为了等待线程结束，如果不调用join函数，主线程会继续往下执行，导致程序提前结束
    cout << "Start\n";
    t1.join();
    cout << "test1\n";
    t2.join();
    cout << "test2\n";
    // cout << "count: " << countnum << "\n"; // count: 2
    int x = 10;
    while (x --> 0) {
        cout << x << "\n";
    }
    return 0;
}