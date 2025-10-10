// 100 points, 0s, C++11

#include <iostream>

int n, v[1000], prime;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if(n % 2 == 0) return false;
    for (int i = 3; i * i < n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    int u = 0;
    for (int i = 0; i < n; i++)
        if (isPrime(v[i])) u = i;
    v[u] = 0;
    for (int i = 0; i < n; i++)
        std::cout << v[i] << ' ';
}