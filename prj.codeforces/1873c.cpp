#include <iostream>
#include <vector>

int main() {
	std::vector<int> result;
	std::string target =
		"1111111111"
		"1222222221"
		"1233333321"
		"1234444321"
		"1234554321"
		"1234554321"
		"1234444321"
		"1233333321"
		"1222222221"
		"1111111111";
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int between_result = 0;
		std::vector<std::string> str_arr;
		for (int j = 0; j < 10; j += 1) {
			std::string s;
			std::cin >> s;
			str_arr.push_back(s);
		}
		for (int m = 0; m < 10; m += 1) {
			int last_m = 0;
			std::string curr_str = str_arr[m];
			for (int k = 0; k < std::count(curr_str.begin(), curr_str.end(), 'X'); k += 1) {
				int ind = curr_str.find('X', last_m);
				last_m += 1;
				int coordinates = (m * 10) + ind; // m*10 --> number of string (x), ind --> number of column (y)
				between_result += (target[coordinates] - '0');
			}
		}
		result.push_back(between_result);
	}
	for (int j = 0; j < result.size(); j += 1) {
		std::cout << result[j] << "\n";
	}
}
