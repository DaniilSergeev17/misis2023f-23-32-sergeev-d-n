#include <iostream>

int main() {
	int w;
	std::cin >> w;
	if (w % 2 == 0 && w > 2) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}
}