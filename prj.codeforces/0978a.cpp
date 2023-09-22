#include <iostream>
#include <vector>

int main() {
	std::vector<int> a;
	std::vector<int> b;
	int v;
	std::cin >> v;
	for (int i = 0; i < v; i += 1) {
		int inp;
		std::cin >> inp;
		a.push_back(inp);
	}
	for (int i = size(a) - 1; i >= 0; i -= 1) {
		bool found = false;
		for (int j = 0; j < b.size(); j += 1) {
			if (a[i] == b[j]) {
				found = true;
			}
		}
		if (!found) {
			b.push_back(a[i]);
		}
	}
	std::cout << b.size() << "\n";
	for (int i = b.size() - 1; i >= 0; i -= 1) {
		std::cout << b[i] << " ";
	}
}