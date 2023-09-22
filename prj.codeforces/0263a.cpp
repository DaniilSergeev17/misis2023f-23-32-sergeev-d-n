#include <iostream>

int main() {
	int row, column, result;
	char n;
	for (int i = 0; i < 5; i += 1) {
		for (int j = 0; j < 5; j += 1) {
			std::cin >> n;
			if (n == '1') {
				row = i;
				column = j;
			}
		}
	}
	result = abs(2 - row) + abs(2 - column);
	std::cout << result;
}