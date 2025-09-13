// 100 points, 0s, C++11

#include <iostream>

long long n;

short cp = -1;

int main() {
    std::cin >> n;
    if (n == 0) cp = 0; // Handle the case when n is 0
    while (n) {
        int c = n % 10;
        if (c % 2 == 0 && c > cp) {
            cp = c;
        }
        n /= 10;
    }
    if (cp == -1) cp = 10;
    std::cout << cp << '\n';
}