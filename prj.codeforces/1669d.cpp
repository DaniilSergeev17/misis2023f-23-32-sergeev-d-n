#include <iostream>
#include <string>

bool valid(int r, int b) {
    bool c1 = r > 0 && b == 0;
    bool c2 = r == 0 && b > 0;
    if (c1 || c2) {
        return false;
    }
    return true;
}

int main() {
    int t = 1;
    std::cin >> t;
    for (int i = 0; i < t; i += 1) {
        int n = 1;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        bool flag = true;
        int r = 0, b = 0;
        for (int i = 0; i < n; i += 1) {
            if (s[i] == 'R') {
                r += 1;
            }
            else if (s[i] == 'B') {
                b += 1;
            }
            else {
                flag = flag && valid(r, b);
                r = 0, b = 0;
            }
        }
        flag = flag && valid(r, b);
        if (flag) {
            std::cout << "YES" << "\n";
        }
        else {
            std::cout << "NO" << "\n";
        }
    }
}