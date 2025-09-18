// 100 points, 0s, C++11

#include <iostream>

long long n;

bool lastp, a = true;

int main() {
    std::cin >> n;
    lastp = n % 10 % 2;
    n /= 10;
    while (n) {
        bool cp = n % 10 % 2;
        n /= 10;
        if (lastp == cp) a = false;
        lastp = cp;
    }
    if (a) std::cout << "da\n";
    else std::cout << "nu\n";
}