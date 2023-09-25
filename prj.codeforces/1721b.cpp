#include <iostream>
#include <vector>

int main() {
	std::vector<int> a;
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int xt = 1, yt = 1;
		int n, m, sx, sy, d;
		std::cin >> n >> m >> sx >> sy >> d;
		if ((std::min(sx - 1, m - sy) > d) || (std::min(n - sx, sy - 1)) > d) {
			a.push_back(n + m - 2);
		}
		else {
			a.push_back(-1);
		}
	}
	for (int i = 0; i < a.size(); i += 1) {
		std::cout << a[i] << "\n";
	}
}