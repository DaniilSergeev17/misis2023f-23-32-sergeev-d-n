#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	std::vector<int> result;
	for (int i = 0; i < t; i += 1) {
		int n, x;
		std::cin >> n >> x;
		std::vector<int> a;
		for (int j = 0; j < n; j += 1) {
			int ent;
			std::cin >> ent;
			a.push_back(ent);
		}
		std::vector<int> b(10005);
		for (int k = 0; k < a.size(); k += 1) {
			if (b[a[k]] != a[k]) {
				b[a[k]] = a[k];
			}
		}
		for (int l = 1; l < b.size(); l += 1) {
			if (b[l] == 0 && x != 0) {
				b[l] = l;
				x -= 1;
			}
		}
		int count = 0;
		int v;
		for (int i = 1; i < b.size(); i += 1) {
			if (b[i] != 0) {
				v = i;
			}
			else {
				break;
			}
		}
		result.push_back(v);
	}
	for (int i = 0; i < result.size(); i += 1) {
		std::cout << result[i] << "\n";
	}
}