#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    unsigned long arr_size = 700001038;
    long long* a = new long long[arr_size];

    for (unsigned long long i = 0; i < arr_size; i++)
        a[i] = rand() % 2 + (-1);

    size_t cnt = 0;
    auto start = chrono::high_resolution_clock::now();
    for (unsigned long long i = 0; i < arr_size; i++)
        if (a[i] >= 0)
            cnt++;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Count = " << cnt << " | Time = " << diff.count() << endl;
    return 0;
}