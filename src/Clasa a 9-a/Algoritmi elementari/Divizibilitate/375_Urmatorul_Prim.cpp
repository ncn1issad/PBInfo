//100 points, 0s, C++11

#include <iostream>

bool found = false;

int n;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i < n; i += 2) {
        if (n % i == 0) return false;
    } return true;
}

int main() {
    std::cin >> n;
    while(!found) {
        n++;
        if (isPrime(n)) found = true;
    }
    std::cout << n;
}