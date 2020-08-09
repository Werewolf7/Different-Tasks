#include <iostream>

int collatz_count_steps_recursion(int N, int count = 0) {
	
	if (N == 1) {
		return count;
	}
	else if (N % 2 == 0) {
		collatz_count_steps_recursion(N / 2, ++count);
	}
	else {
		collatz_count_steps_recursion(N * 3 + 1, ++count);
	}
}

int main() {
	int N;
	std::cout << "Input N (N > 1): ";
	std::cin >> N;
	std::cout << collatz_count_steps_recursion(N);
}