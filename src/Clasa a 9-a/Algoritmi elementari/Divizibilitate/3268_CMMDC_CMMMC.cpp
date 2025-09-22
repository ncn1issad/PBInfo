// 100 points, 0s, C++11

#include <iostream>

long long a, b, D, M;

long long gcd(long long x, long long y) {
    while (x && y) {
        if (x > y) x %= y;
        else y %= x;
    }
    if (x) return x;
    else return y;
}

int main() {
    std::cin >> a >> b;
    D = gcd(a, b);
    M = a / D * b;
    std::cout << D << ' ' << M;
}