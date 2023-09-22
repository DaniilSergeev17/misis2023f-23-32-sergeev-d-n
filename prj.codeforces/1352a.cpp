#include <iostream>
#include <string>
#include <vector>

bool is_beautiful(int n) {
	return ((n % std::stoi(std::to_string(pow(10, std::to_string(n).length() - 1)))) == 0) && (std::to_string(n).length() > 1);
}

int main() {
	int num, n, res, length, c = 0;
	std::cin >> num;
	std::vector<int> a(num);
	for (int i = 0; i < num; i += 1) {
		std::cin >> n;
		a[i] = n;
	}

	for (int i = 0; i < num; i += 1) {
		std::vector<int> b;
		res = a[i];
		c = 0;
		if (is_beautiful(res)) {
			std::cout << 1 << "\n";
			std::cout << res << std::endl;
			continue;
		}
		else {
			while (res / 10 >= 1) {
				if (is_beautiful(res)) {
					break;
				}
				else {
					length = std::to_string(res).length();
					b.push_back(floor(res / pow(10, (length - 1))) * pow(10, (length - 1)));
					res = res - b[c];
					c += 1;
				}
			}
			b.push_back(res);
		}
		std::cout << size(b) << "\n";
		for (int j = 0; j < size(b); j += 1) {
			std::cout << b[j] << " ";
		}
		std::cout << std::endl;
	}
}
