#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    unsigned long arr_size = 700001038;
    unsigned long long* a = new unsigned long long[arr_size];

    int Delta = 1;

    if(argc > 1)
        Delta = atoi(argv[1]);
    if (Delta < 1)
        Delta = 1;

    cout << "Заполняем массив" << endl;
    for (unsigned long long i = 0; i < arr_size; i++)
        a[i] = rand();

    unsigned long long Sum = 0;
    auto start = std::chrono::high_resolution_clock::now();

    cout << "Начинаем считать сумму" << endl;
    for (unsigned long long i = 0; i < arr_size; i += Delta)
        Sum += a[i];

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Delta = "<< Delta << " | Sum = " << Sum << " | Time = " << diff.count() << endl;
    return 1;
}