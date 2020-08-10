//Перевернуть массив

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>



int main()
{
    std::vector<int> arr{ std::istream_iterator<int>(std::cin), std::istream_iterator<int>() };
    reverse(arr.begin(), arr.end());
    copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
}
