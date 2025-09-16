// 100 points, 0s, C++11

#include <iostream>

long long n, m, s = 0;

int main() {
    std::cin >> n;
    while (n) {
        m = m * 10 + n % 10;
        s += n % 10;
        n /= 10;
    }
    if (m % 10 == s - m % 10)
        std::cout << "DA\n";
    else
        std::cout << "NU\n";
    return 0;
}