//Найти в массиве повторяющиеся значения

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    vector<int> arr{ istream_iterator<int>(cin), istream_iterator<int>() };
    set<int> non_unique;
    for_each(
        arr.begin(),
        arr.end(),
        [&arr, &non_unique](int el) {
            if (count(arr.begin(), arr.end(), el) > 1) { non_unique.insert(el); }
        }
    );
    copy(non_unique.begin(), non_unique.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
