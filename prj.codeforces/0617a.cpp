#include <iostream>

int main() {
    int x, count = 0;
    std::cin >> x;
    for (int i = 5; i >= 1; i -= 1) {
        count += x / i;
        x = x - (x / i) * i;
    }
    std::cout << count;
}