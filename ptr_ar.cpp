/*
Написать программу, в соответствии с заданием с использованием динамических массивов, вводя размер массива с клавиатуры и используя имя массива как указатель, применить адресную арифметику для работы с элементами массива.

Дан одномерный массив, состоящий из N целочисленных элементов:
1. Заполнить массив случайными числами.
2. Найти минимальный отрицательный элемент.
3. Вычислить произведение ненулевых элементов массива, кратных 3.
4. Вывести отрицательные элементы на экран в обратном порядке.
*/

#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

int* create_arr(int size) {
    int* arr = new int[size];
    return arr;
}
void fill_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % 41 - 20;
    }
}
int find_min_el(int* arr, int size) {
    int min = *(arr);
    for (int i = 0; i < size; i++) {
        if (*(arr + i) < min)
            min = *(arr + i);
    }
    return min;
}
int mult(int* arr, int size) {
    int mltp = 1;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) != 0 && *(arr + i) % 3 == 0)
            mltp *= *(arr + i);
    }
    return mltp;
}
void show_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
}
void reverse_show(int* arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (*(arr + i) < 0)
            cout << *(arr + i) << " ";
    }
}
int main(){
    

    srand(time(NULL));
    int size;
    cin >> size;
    int* arr = create_arr(size);
    fill_arr(arr, size);
    cout << find_min_el(arr, size) << endl;
    cout << mult(arr, size) << endl;
    show_arr(arr, size);
    cout << endl;
    reverse_show(arr, size);
    delete[] arr;
    return 0;
}
