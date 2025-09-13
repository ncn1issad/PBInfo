// 100 points, 0s, C++11

#include <iostream>

long long n, s = 0;

int main() {
    std::cin >> n;
    while (n) {
        int c = n % 10;
        if (c >= 3 && c <= 7) {
            s += c;
        }
        n /= 10;
    }
    std::cout << s << '\n';
    return 0;
}