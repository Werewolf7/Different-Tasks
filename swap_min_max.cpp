//Найти наибольший и наименьший элементы массива и поменять их в массиве местами

#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    std::array<int, 6> arr = { 1, 2, 5, 0, 3, 6 };
    const auto [min_it, max_it] = minmax_element(begin(arr), end(arr));
    iter_swap(min_it, max_it);

    for (const auto& item : arr) {
        cout << item << '\n';
    }
}
