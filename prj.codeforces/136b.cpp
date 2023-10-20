#include <iostream>
#include <string>

std::string to_three(int a) {
	int c = a;
	std::string res = "";
	while (c > 0) {
		std::string str = std::to_string(c % 3);
		res += str;
		c /= 3;
	}
	std::string result = "";
	for (int i = res.size() - 1; i >= 0; i -= 1) {
		result += res[i];
	}
	return result;
}
int main() {
	std::string a = "";
	std::string c = "";
	std::cin >> a >> c;
	a = to_three(std::stoi(a));
	c = to_three(std::stoi(c));
	if (a.size() < c.size()) {
		while (a.size() < c.size()) {
			a = "0" + a;
		}
	}
	else {
		while (c.size() < a.size()) {
			c = "0" + c;
		}
	}
	std::string result = "";
	for (int j = 0; j < a.size(); j += 1) {
		std::string res = std::to_string(((a[j] - '0') + (c[j] - '0')) % 3);
		result += res;
	}
	std::string final_result = "";
	for (int j = 0; j < result.size(); j += 1) {
		std::string res = std::to_string(((result[j] - '0') + (a[j] - '0')) % 3);
		final_result += res;
	}
	int ch = 0;
	for (int i = 0; i < final_result.size(); i += 1) {
		ch += (final_result[i] - '0') * std::pow(3, final_result.size() - i - 1);
	}
	std::cout << ch;
}