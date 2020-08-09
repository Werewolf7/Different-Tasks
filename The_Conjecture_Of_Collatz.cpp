#include <iostream>

int collatz_count_steps(int N) {
	int count = 0;
	while (N != 1) {
		N % 2 == 0 ? N /= 2 : N = N * 3 + 1;
		count++;
	}
	return count;
}

int main() {
	int N;
	std::cout << "Input N (N > 1): ";
	std::cin >> N;
	std::cout << collatz_count_steps(N);
}