// O(n^0.5/2) time complexity

#include <iostream>
#include <cmath>

/**
 * @brief Returns the smallest prime divisor of a given integer n.
 * 
 * If n is even, returns 2. Otherwise, checks all odd numbers starting from 3 up to sqrt(n)
 * and returns the first divisor found. If no divisors are found, returns n itself (which means n is prime).
 * 
 * @param n The integer to find the smallest prime divisor for.
 * @return int The smallest prime divisor of n.
 */
int findSmallestPrimeDivisor(long long n) {
    if (n % 2 == 0) return 2;
    for (long long i = 3; i < std::sqrt(n); i += 2) {
        if (n % i == 0) return i;
    }
    return n;
}

int main() {
    long long n;
    std::cin >> n;
    int spd = findSmallestPrimeDivisor(n);
    std::cout << "The smallest prime divisor of " << n << " is " << spd << ".\n";
    return 0;
}