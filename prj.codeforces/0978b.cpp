#include <iostream>

int main() {
	int s;
	std::cin >> s;
	std::string a;
	std::cin >> a;
	int x = 0;
	while (a.find("xxx") != std::string::npos) {
		a.replace(a.find("xxx"), 3, "xx");
		x += 1;
	}
	std::cout << x;
}