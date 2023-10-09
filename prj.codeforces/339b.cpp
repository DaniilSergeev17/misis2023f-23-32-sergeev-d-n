#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> ai(m);
	for (int i = 0; i < m; i += 1) {
		std::cin >> ai[i];
	}

	int result = 0;
	int curr_house = 1;

	for (int j = 0; j < m; j += 1) {
		if (ai[j] >= curr_house) {
			result += ai[j] - curr_house;
		}
		else {
			result += n - curr_house + ai[j];
		}
		curr_house = ai[j];
	}

	std::cout << result;
}