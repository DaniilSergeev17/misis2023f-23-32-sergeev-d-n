#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int a, b, c;
		std::cin >> a >> b >> c;
		double diff = (a + b) / 2.0;
		double res = std::abs(a - diff);
		int result = std::ceil(res / c);
		vec.push_back(result);
	}
	for (int i = 0; i < size(vec); i += 1) {
		std::cout << vec[i] << "\n";
	}
}