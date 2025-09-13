// 100 points, 0s, C++11

#include <iostream>

long long n, s = 0;

int main() {
    std::cin >> n;
    while (n) {
        s += n;
        n /= 10;
    }
    std::cout << s << '\n';
    return 0;
}