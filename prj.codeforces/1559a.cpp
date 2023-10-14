#include <iostream>
#include <vector>

int main() {
	std::vector<int> result;
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int n;
		std::cin >> n;
		int flag = true;
		int res = 0;
		std::vector<int> a(n);
		for (int j = 0; j < n; j += 1) {
			std::cin >> a[j];
			if (flag) {
				res = a[j];
				flag = false;
			}
			res = res & a[j];
		}
		result.push_back(res);
	}
	for (int j = 0; j < t; j += 1) {
		std::cout << result[j] << "\n";
	}
}