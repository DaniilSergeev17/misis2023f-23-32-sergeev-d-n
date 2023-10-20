#include <iostream>
#include <string>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int n = 2;
		std::cin >> n;
		int cord1 = 0; // 100, 200, ... --> coordinates of column and 101, 102, ...--> of str's
		int cord2 = 0;
		std::vector<std::string> a;
		bool flag1 = true;
		for (int j = 0; j < n; j += 1) {
			std::string ch;
			std::cin >> ch;
			auto flag = ch.find('*');
			if (flag != std::string::npos) {
				if (flag1) {
					cord1 = ((flag + 1) * 100) + j + 1;
				}
				else {
					cord2 = ((flag + 1) * 100) + j + 1;
				}
				flag1 = false;
			}
			a.push_back(ch);
		}
		int toch1 = 0;
		int toch2 = 0;
		if (((cord1 / 100) != (cord2 / 100)) && ((cord1 % 10) != (cord2 % 10))) {
			toch1 = (cord2 / 100) * 100 + (cord1 % 10);
			toch2 = (cord1 / 100) * 100 + (cord2 % 10);
		}
		else {
			if ((cord1 / 100) == (cord2 / 100)) {
				if (cord1 / 100 == 1) {
					toch1 = (cord2 / 100 + 1) * 100 + (cord1 % 10);
					toch2 = (cord1 / 100 + 1) * 100 + (cord2 % 10);
				}
				else {
					toch1 = (cord2 / 100 - 1) * 100 + (cord1 % 10);
					toch2 = (cord1 / 100 - 1) * 100 + (cord2 % 10);
				}
			}
			else {
				if (cord1 % 10 == 1) {
					toch1 = (cord2 / 100) * 100 + (cord1 % 10 + 1);
					toch2 = (cord1 / 100) * 100 + (cord2 % 10 + 1);
				}
				else {
					toch1 = (cord2 / 100) * 100 + (cord1 % 10 - 1);
					toch2 = (cord1 / 100) * 100 + (cord2 % 10 - 1);
				}
			}
		}
		int coltoch1 = toch1 / 100 - 1;
		int strtoch1 = toch1 % 10 - 1;
		int coltoch2 = toch2 / 100 - 1;
		int strtoch2 = toch2 % 10 - 1;
		for (int s = 0; s < a.size(); s += 1) {
			if (s == strtoch1) {
				a[s][coltoch1] = '*';
			}
			if (s == strtoch2) {
				a[s][coltoch2] = '*';
			}
		}
		for (int s = 0; s < a.size(); s += 1) {
			std::cout << a[s] << "\n";
		}
	}
}