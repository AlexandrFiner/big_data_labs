#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "omp.h"

using namespace std;

int main()
{
    double **a, **b, **c;
    int row1, col1,
        row2, col2;

    int mode;
    cout << "Ручной режим ввода - 1 | Ввод из файла - 2: ";
    cin >> mode;

    if (mode == 1) {
        cout << "Введите количество строк матирцы A: ";
        cin >> row1;
        cout << "Введите количество столбцов матрицы А: ";
        cin >> col1;
        cout << "Введите количество строк матирцы B: ";
        cin >> row2;
        cout << "Введите количество столбцов матрицы B: ";
        cin >> col2;

        if (col1 != row2) {
            cout
                    << "Ошибка! Такие матрицы нельзя перемножить, так как количество столбцов матрицы А не равно количеству строк матрицы В."
                    << endl;
            return 1;
        }

        a = new double * [row1];
        cout << "Введите элементы матрицы А" << endl;
        for (int i = 0; i < row1; i++) {
            a[i] = new double[col1];
            for (int j = 0; j < col1; j++) {
                cout << "a[" << i+1 << "][" << j+1 << "] = ";
                cin >> a[i][j];
            }
        }

        b = new double * [row2];
        cout << "Введите элементы матрицы B" << endl;
        for (int i = 0; i < row2; i++) {
            b[i] = new double[col2];
            for (int j = 0; j < col2; j++) {
                cout << "b[" << i+1 << "][" << j+1 << "]= ";
                cin >> b[i][j];
            }
        }
    } else {
        row1 = 80;
        row2 = 80;
        col1 = 80;
        col2 = 80;

        a = new double* [row1];
        for (int i = 0; i < row1; i++) {
            a[i] = new double[col2];
            for (int j = 0; j < col2; j++) {
                a[i][j] = 0;
            }
        }

        b = new double* [row1];
        for (int i = 0; i < row1; i++) {
            b[i] = new double[col2];
            for (int j = 0; j < col2; j++) {
                b[i][j] = 0;
            }
        }

        string path = "matrix_20.txt";
        ifstream fin;
        fin.open(path);
        if (!fin.is_open()) {
            cout << "Ошибка чтения файла" << endl;
            return 1;
        } else {
            int value = 0;
            for (int i = 0; i < row1; i++) {
                for (int j = 0; j < col1; j++) {
                    fin >> value;
                    a[i][j] = value;
                    b[i][j] = value;
                }
            }
        }
    }

//    cout << endl << "Матрица А" << endl;
//    for (int i = 0; i < row1; i++) {
//        for (int j = 0; j < col1; j++)
//            cout << a[i][j] << " ";
//        cout << endl;
//    }
//
//    cout << endl << "Матрица B" << endl;
//    for (int i = 0; i < row2; i++) {
//        for (int j = 0; j < col2; j++)
//            cout << b[i][j] << " ";
//        cout << endl;
//    }

    // calc start

    auto start = chrono::high_resolution_clock::now();
    c = new double* [row1];
    for (int i = 0; i < row1; i++) {
        c[i] = new double[col2];
        for (int j = 0; j < col2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < col1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

//    omp_set_num_threads(8);   // устанавливаем количество потоков 8
//    int i, j, k;
//#pragma omp parallel for shared(a, b, c) private(i, j, k)
//    for (i = 0; i < row1; i++) {
//        for (j = 0; j < col2; j++) {
//            for (k = 0; k < col1; k++) {
//                c[i][j] += (a[i][k] * b[k][j]);
//            }
//            printf("Thread %i: С[%i][%i]= %f\n", omp_get_thread_num(), i, j, c[i][j]);
//        }
//    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
//    cout << "Time = " << diff.count() << endl;

    // calc end

//    cout << endl << "Матрица произведения:" << endl;
//    for (int i = 0; i < row1; i++) {
//        for (int j = 0; j < col2; j++)
//            cout << c[i][j] << " ";
//        cout << endl;
//    }

    cout << "Time = " << diff.count() << endl;



    return 0;
}