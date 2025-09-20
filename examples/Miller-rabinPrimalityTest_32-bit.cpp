#include <iostream>

/**
 * @brief Computes (a * b) % mod using 64-bit arithmetic to avoid overflow.
 *
 * This function multiplies two unsigned integers a and b, then takes the result modulo mod.
 * It uses 64-bit arithmetic to ensure correctness for large values of a and b, preventing overflow
 * that could occur with 32-bit multiplication.
 *
 * @param a The first unsigned integer operand.
 * @param b The second unsigned integer operand.
 * @param mod The modulus.
 * @return The result of (a * b) % mod as an unsigned integer.
 */
unsigned int mul(unsigned int a, unsigned int b, unsigned int mod) {
    return static_cast<unsigned int>((static_cast<unsigned long long>(a) * b) % mod);
}

/**
 * Computes (base^exp) % mod using modular exponentiation.
 *
 * This function efficiently calculates the result of raising `base` to the power of `exp`,
 * modulo `mod`, using the binary exponentiation method. It relies on a helper function `mul`
 * to perform modular multiplication safely.
 *
 * @param base The base of the exponentiation.
 * @param exp The exponent.
 * @param mod The modulus.
 * @return The value of (base^exp) % mod.
 */
unsigned int power(unsigned int base, unsigned int exp, unsigned int mod) {
    unsigned int res = 1;
    base %= mod;
    while (exp) {
        if (exp % 2 == 1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp /= 2;
    }
    return res;
}

/**
 * @brief Checks if a number is composite using a single round of the Miller-Rabin primality test.
 *
 * This function determines whether the given number `n` is composite with respect to a witness `a`,
 * using the decomposition of `n-1` as `d * 2^s`. It is used internally by the Miller-Rabin test.
 *
 * @param n The number to test for compositeness.
 * @param a The witness base for the test.
 * @param d The odd part of n-1, such that n-1 = d * 2^s.
 * @param s The exponent of 2 in the decomposition of n-1.
 * @return true if `n` is definitely composite with respect to `a`, false if `n` is probably prime.
 */
bool checkComposite(unsigned int n, unsigned int a, unsigned int d, int s) {
    unsigned  int x = power(a, d, n);
    // If a^d % n == 1 or a^d % n == n-1, n is probably prime.
    if (x == 1 || x == n - 1) return false;
    // Keep squaring x while d does not become n-1
    for (int r = 1; r < s; r++) {
        x = mul(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}

/**
 * @brief Determines if a given unsigned 32-bit integer is prime using the Miller-Rabin primality test.
 *
 * This function uses a deterministic version of the Miller-Rabin test with bases {2, 7, 61},
 * which is sufficient for all 32-bit integers. It first handles small cases and even numbers,
 * then decomposes n-1 into d * 2^s, and tests the number against the selected bases.
 *
 * @param n The unsigned integer to test for primality.
 * @return true if n is prime, false otherwise.
 */
bool isPrime(unsigned int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    // Write n-1 as d * 2^s, where d is odd.
    unsigned int d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1; // d /= 2;
        s++;
    }
    // For all 32-bit integers, this set of three bases is sufficient
    // to deterministically prove primality.
    unsigned int bases[] = {2, 7, 61};
    for (unsigned int a : bases) {
        if (n == a) return true;
        if (checkComposite(n, a, d, s)) return false;
    }
    return true;
}

int main() {
    // A list of numbers to test within the 32-bit range
    unsigned int test_numbers[] = {
        7,                           // Small prime
        97,                          // Prime
        561,                         // Carmichael number (composite)
        1000000007,                  // A common prime in competitive programming
        2147483647,                  // 31st Mersenne prime (prime)
        4294967291U,                 // A large 32-bit prime
        4294967295U                  // Max unsigned int (composite)
    };

    std::cout << "Running Miller-Rabin Primality Test (Optimized for 32-bit)...\n\n";
    for (unsigned int n : test_numbers) {
        std::cout << n << " is " << (isPrime(n) ? "Prime" : "Composite") << ".\n";
    }

    return 0;
}