#include <iostream>
#include <string>

int main() {
	int result = 0;
	std::string a;
	std::cin >> a;
	char b = 'a';
	for (int i = 0; i < a.size(); i += 1) {
		int maxi = std::max(a[i], b);
		int mini = std::min(a[i], b);
		int res = std::min(maxi - mini, mini - 'a' + (26 - (maxi - 'a')));
		b = a[i];
		result += res;
	}
	std::cout << result << "\n";
}