#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

bool binary_search(const std::vector<int>& arr, const int& key) {
	int first = 0;
	int last = arr.size() - 1;
	bool res = false;
	while (first <= last) {
		int middle = (first + last) / 2;
		if (arr[middle] == key) {
			return true;
		}
		else if (arr[middle] > key) {
			last = middle - 1;
			middle = (first + last) / 2;
		}
		else {
			first = middle + 1;
			middle = (first + last) / 2;
		}
	}
	return false;
	
	
}

int main() {
	int el = 2;
	std::cout << "Input vector: ";
	std::vector<int> arr{ std::istream_iterator<int>(std::cin), std::istream_iterator<int>() };
	std::sort(arr.begin(), arr.end());
	std::cout << binary_search(arr, el);
}