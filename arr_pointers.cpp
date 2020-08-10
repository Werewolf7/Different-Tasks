//Создать массив указателей на функции. Функции выполняют арифметические действия

#include <iostream>
#include <string>
#include <vector>
#include <functional>


int add(const int x, const int y) {
    return x + y;
}
int subtract(const int x, const int y) {
    return x - y;
}
int multiply(const int x, const int y) {
    return x * y;
}
int division(const int x, const int y) {
    return x / y; 
}
int main()
{
    std::vector<std::function<int(int, int)>> arr{ add, subtract, multiply, division };
    int x, y;
    std::cin >> x >> y;
    for (auto i : arr) {
        std::cout << i(x, y) << " ";
    }
}
