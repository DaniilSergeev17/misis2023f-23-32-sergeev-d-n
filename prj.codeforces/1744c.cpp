#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i += 1) {
        int s = 0;
        int maxi = 0;
        int k = 0;
        bool flag = false;
        char r;
        std::string st;
        std::cin >> s >> r;
        std::cin >> st;
        for (int j = 0; j < s; j += 1) {
            if (flag) {
                if (st[j] == 'g') {
                    if (k > maxi) {
                        maxi = k;
                    }
                    k = 0;
                    flag = false;
                }
                else {
                    k += 1;
                }
            }
            else {
                if (st[j] == r) {
                    k += 1;
                    flag = true;
                }
            }
        }
        for (int j = 0; j < s; j += 1) {
            if (!flag) {
                break;
            }
            if (flag) {
                if (st[j] == 'g') {
                    if (k > maxi) {
                        maxi = k;
                    }
                    break;
                }
                else {
                    k += 1;
                }
            }
            else {
                break;
            }
        }
        if (r == 'g') {
            std::cout << 0 << '\n';
        }
        else {
            std::cout << maxi << '\n';
        }
    }

}