
#include <iostream>

int n, divTotal = 0;

// 90 points, 0s, C++11

int main_deprecated() {
    std::cin >> n;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            if (divTotal) {
                divTotal += i;
                break;
            } else {
                divTotal = i;
            }
        }
    }
    std::cout << divTotal;
    return 0;
}

// 100 points, 0s, C++11

#include <cmath>

int d1, d2;

int fsp(int n) {
    if (n % 2 == 0) return 2;
    for (int i = 3; i < std::sqrt(n); i += 2) {
        if (n % i == 0) return i;
    }
    return n;
}

int main() {
    std::cin >> n;
    d1 = fsp(n);
    int cn = n;
    while (cn % d1 == 0) cn /= d1;
    if (cn == 1) d2 = d1 * d1;
    else {
        int candA = d1 * d1;
        if (n % candA == 0) {
            if (d1 * d1 < fsp(cn)) d2 = d1 * d1;
            else d2 = fsp(cn);
        } else d2 = fsp(cn);
    }
    std::cout << d1 + d2;
    return 0;
}