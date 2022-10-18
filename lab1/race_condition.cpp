#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Чтобы исправить race condition используем mutex
mutex m1;

// shared print function for cout
void shared_print(char c, int v) {
    m1.lock();
    cout << c << v << "\n";
    m1.unlock();
}

void foo(char d, int a) {
    for (int i = 1; i <= a; i++) {
        shared_print(d, i);
    }
}

int main()
{
    thread t1(foo, 'A', 10);
    thread t2(foo, 'B', 10);
    thread t3(foo, 'C', 10);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}