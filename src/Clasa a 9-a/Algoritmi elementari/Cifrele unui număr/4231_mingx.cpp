// 100 points, 0s, C++11

#include <iostream>

long long n;

short x, cm = 10;

int main() {
    std::cin >> n >> x;
    while (n) {
        if (n % 10 < cm && n % 10 > x) cm = n % 10;
        n /= 10;
    }
    if (cm == 10) std::cout << -1 << '\n';
    else std::cout << cm << '\n';
    return 0;
}