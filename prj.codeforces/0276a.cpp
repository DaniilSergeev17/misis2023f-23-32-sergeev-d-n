#include <iostream>

int main() {
	int n, t, maxi = pow(-10, 9);
	std::cin >> n >> t;
	for (int i = 0; i < n; i += 1) {
		int fi, ti;
		std::cin >> fi >> ti;
		if (ti > t) {
			maxi = std::max(maxi, fi - (ti - t));
		}
		else {
			maxi = std::max(maxi, fi);
		}
	}
	std::cout << maxi;
}