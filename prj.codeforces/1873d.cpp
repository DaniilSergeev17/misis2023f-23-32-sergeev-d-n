#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	std::vector<int> result(t, 0);

	for (int i = 0; i < t; i += 1) {
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;

		int count = 0;
		size_t pos = 0;

		while ((pos = s.find('B', pos)) != std::string::npos) {
			s.replace(pos, k, k, 'W'); // Заменяем k символов 'B' на 'W'
			count += 1;
		}
		result[i] = count;
	}

	for (int j = 0; j < t; j += 1) {
		std::cout << result[j] << "\n";
	}

	return 0;
}