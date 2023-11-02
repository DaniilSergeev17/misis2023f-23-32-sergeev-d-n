#include <iostream>
#include <vector>
#include <string>

int solution(int n, int k, std::string a) {
	std::vector<int> v(n+1, 0);
	for (int i = 1; i <= n; i += 1) {
		v[i] = v[i - 1] + (a[i - 1] == 'W');
	}
	int min_white = n;
	for (int i = k; i <= n; i += 1) {
		int left = i - k + 1;
		int right = i;

		int white_cells = v[right] - v[left - 1];
		min_white = std::min(min_white, white_cells);
	}
	return min_white;
}

int main() {
	int t = 1;
	std::cin >> t;
	std::vector<int> results;
	for (int i = 0; i < t; i += 1) {
		int n = 1;
		int k = 1;
		std::cin >> n >> k;
		std::string a;
		std::cin >> a;
		int result = solution(n, k, a);
		results.push_back(result);
	}
	for (int i = 0; i < t; i += 1) {
		std::cout << results[i] << "\n";
	}
}