#include <iostream>
#include <vector>

int main() {
	std::vector<int> result;
	int count = 0;
	int t = 1;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		bool flag = false;
		int n = 2;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		int k = 1;
		std::cin >> k;
		std::vector<char> b;
		for (int j = 0; j < k; j += 1) {
			char m;
			std::cin >> m;
			b.push_back(m);
		}
		int count = 0;
		std::vector<std::string> st(n + 1);
		st[0] = s;
		std::string last = "";
		for (int le = 0; le < st.size() - 1; le += 1) {
			std::string q = st[le];
			if (st[le].empty() != 1 && last != st[le]) {
				for (int ind = 0; ind < st[le].size() - 1; ind += 1) {
					if (std::find(b.begin(), b.end(), q[ind + 1]) != b.end()) {
						q[ind] = ' ';
					}
				}
				std::string helpp = "";
				for (int e = 0; e < q.size(); e += 1) {
					if (q[e] != ' ') {
						helpp += q[e];
					}
				}
				st[le + 1] = helpp;
				last = st[le];
			}
			else {
				break;
			}
		}
		for (int l = 0; l < st.size(); l += 1) {
			if (st[l] != last) {
				count += 1;
			}
			else {
				break;
			}
		}
		result.push_back(count);
		count = 0;
	}

	for (int d = 0; d < result.size(); d += 1) {
		std::cout << result[d] << "\n";
	}
}