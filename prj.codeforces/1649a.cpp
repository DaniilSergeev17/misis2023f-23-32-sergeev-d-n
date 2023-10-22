#include <iostream>
#include <vector>

int main() {
	std::vector<int> result;
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int n = 2;
		std::cin >> n;
		std::vector<int> a(n);
		for (int j = 0; j < n; j += 1) {
			std::cin >> a[j];
		}
		int ind_to_jump = 0;
		for (int j = 0; j < n; j += 1) {
			if (a[j] == 0) {
				ind_to_jump = j + 1;
			}
		}
		if (ind_to_jump == 0) {
			result.push_back(0);
		}
		else {
			int ind_from_jump = 0;
			for (int j = 0; j < n; j += 1) {
				if (a[j] == 0) {
					break;
				}
				else {
					ind_from_jump = j;
				}
			}
			result.push_back(ind_to_jump - ind_from_jump);
		}

	}
	for (int i = 0; i < result.size(); i += 1) {
		std::cout << result[i] << "\n";
	}
}