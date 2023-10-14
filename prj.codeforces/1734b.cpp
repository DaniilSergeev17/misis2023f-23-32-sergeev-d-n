#include <iostream>
#include <vector>

int main() {
	std::vector<std::vector<std::string>> result;
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int n;
		std::cin >> n; // #floors in this case
		std::vector<std::vector<int>> a;
		for (int j = 1; j <= n; j += 1) {
			std::vector<int> m(j, 0);
			a.push_back(m);
		}
		a[0][0] = 1;
		std::vector<std::string> res = { "1 " };
		for (int r = 1; r < a.size(); r += 1) {
			std::string s = "1 ";
			for (int j = 0; j <= r; j += 1) {
				if (j != 0 && j != r) {
					s += "0 ";
				}
				else {
					if (j == r) {
						s += '1';
					}
				}
			}
			res.push_back(s);
		}
		result.push_back(res);
	}
	for (int i = 0; i < result.size(); i += 1) {
		for (int j = 0; j < result[i].size(); j += 1) {
			std::cout << result[i][j] << "\n";
		}
	}
}