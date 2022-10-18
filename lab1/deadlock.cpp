#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int main() {
    mutex m1;
    mutex m2;

    thread t1([&m1, &m2] {
        cout << "1. Acquiring m1." << endl;
        m1.lock();
        this_thread::sleep_for(chrono::microseconds(10));
        cout << "1. Acquiring m2." << endl;
        m2.lock();
    });

    t1.join();
    return 1;
}