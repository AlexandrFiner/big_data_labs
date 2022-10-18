#include <iostream>

using namespace std;

int main()
{
    unsigned long arr_size = 751201038;
    unsigned long long* a = new unsigned long long[arr_size];

    for (unsigned long long i = 0; i < arr_size; i++) {
        a[i] = rand();
    }
    while (true) {} // Чтобы программа не завершилась
}