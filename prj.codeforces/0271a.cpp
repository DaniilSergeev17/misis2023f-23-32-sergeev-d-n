#include <iostream>

int main() {
	int y, count = 0;
	std::cin >> y;
	int first, second, third, forth;
	for (int i = y + 1; i <= 9999; i += 1) {
		first = i / 1000;
		second = i / 100 % 10;
		third = i / 10 % 10;
		forth = i % 10;
		if (first != second && first != third && first != forth && second != third && second != forth && third != forth) {
			std::cout << i;
			break;
		}
	}
}