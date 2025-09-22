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

/**
 * @brief Returns the smallest prime divisor of a given integer n.
 * 
 * If n is even, returns 2. Otherwise, checks all odd numbers starting from 3 up to sqrt(n)
 * and returns the first divisor found. If no divisors are found, returns n itself (which means n is prime).
 * 
 * @param n The integer to find the smallest prime divisor for.
 * @return int The smallest prime divisor of n.
 */
int fsp(int n) {
    if (n % 2 == 0) return 2;
    for (int i = 3; i < std::sqrt(n); i += 2) {
        if (n % i == 0) return i;
    }
    return n;
}

int main() {
    std::cin >> n;
    // Finds the smallest prime divisor of n
    d1 = fsp(n);
    // Removes all occurrences of d1 from n
    int cn = n;
    while (cn % d1 == 0) cn /= d1;
    // Determines d2 based on the remaining value of cn
    if (cn == 1) d2 = d1 * d1;
    else {
        int candA = d1 * d1;
        // If n is divisible by d1^2, then d2 is either d1^2 or the smallest prime divisor of cn, whichever is smaller
        if (n % candA == 0) {
            if (d1 * d1 < fsp(cn)) d2 = d1 * d1;
            else d2 = fsp(cn);
        } else d2 = fsp(cn);
    }
    std::cout << d1 + d2;
    return 0;
}