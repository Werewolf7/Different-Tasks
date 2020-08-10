#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;


int main() {

    vector<int> arr{ istream_iterator<int>(cin), istream_iterator<int>() };
    cout << accumulate(arr.begin(), arr.end(), 0,
        [](int sum, int el)
        { if (el < 0) sum++; return sum; })
        << endl;
}