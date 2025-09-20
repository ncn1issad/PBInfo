// 100 points, 0s, C++11

#include <iostream>

int n;
long long s = 0;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    std::cin >> n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (!isPrime(i)) s += i;
            if (i != n / i) {
                int j = n / i;
                if (!isPrime(j)) s+= j;
            }
        }

    }
    std::cout << s;
}