#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

// По возрастанию
int comp1 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    unsigned long arr_size = 700001038;
    long long* a = new long long[arr_size];

    for (unsigned long long i = 0; i < arr_size; i++)
        a[i] = rand() % 2 + (-1);

    cout << "Началась сортировка" << endl;
    qsort (a, arr_size, sizeof(int), comp1);
    cout << "Начался подсчет" << endl;

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