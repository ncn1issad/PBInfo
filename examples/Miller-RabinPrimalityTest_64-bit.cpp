#include <iostream>

/**
 * Performs modular multiplication of two unsigned 64-bit integers without overflow unsing the Russian Peasant Multiplication method.
 *
 * This function computes (a * b) % mod in a way that avoids overflow by using
 * addition and bit manipulation, making it suitable for very large values of a and b.
 *
 * @param a   The first operand.
 * @param b   The second operand.
 * @param mod The modulus.
 * @return    The result of (a * b) % mod.
 */
unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long res = 0;
    a %= mod;
    while (b) {
        // If the current bit of b is 1, add a to the result.
        if(b & 1) {
            // Add 'a' to 'res' using an overflow-safe method
            // (res + a) % mod;
            if (a >= mod - res) res = a - (mod - res);
            else res += a;
        }
        // Double 'a' (with wraparound), also overflow-safe.
        // (a * 2) % mod;
        if (a >= mod - a) a = a - (mod - a);
        else a += a;
        // Move to the next bit of b.
        b >>= 1;
    }
    return res;
}

/**
 * Computes (base^exp) % mod using modular exponentiation.
 *
 * This function efficiently calculates the result of raising `base` to the power of `exp`,
 * modulo `mod`, using the binary exponentiation method. It relies on a helper function `mul`
 * to perform modular multiplication safely for large numbers.
 *
 * @param base The base value to be exponentiated.
 * @param exp The exponent value.
 * @param mod The modulus value.
 * @return The result of (base^exp) % mod.
 */
unsigned long long power(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp /= 2;
    }
    return res;
}

/**
 * @brief Checks if a number is composite using a single iteration of the Miller-Rabin primality test.
 *
 * This function tests whether the given number `n` is composite with respect to a witness `a`,
 * using the decomposition of `n-1` as `d * 2^s`. It computes `x = a^d mod n` and then squares `x`
 * up to `s-1` times, checking for non-trivial roots of unity modulo `n`.
 *
 * @param n The number to test for compositeness.
 * @param a The witness base for the Miller-Rabin test.
 * @param d The odd part of n-1, such that n-1 = d * 2^s.
 * @param s The exponent of 2 in the decomposition of n-1.
 * @return true if `n` is definitely composite with respect to witness `a`, false if `n` is probably prime.
 */
bool checkComposite(unsigned long long n, unsigned long long a, unsigned long long d, int s) {
    unsigned long long x = power(a, d, n);
    // If a^d % n == 1 or a^d % n == n-1, n is probably prime.
    if (x == 1 || x == n - 1) return false;
    // Keep squaring x while d does not become n-1
    for (int r = 1; r < s; r++) {
        x = mul (x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}

/**
 * @brief Determines whether a given 64-bit unsigned integer is prime using the Miller-Rabin primality test.
 *
 * This function implements a deterministic version of the Miller-Rabin primality test for 64-bit integers.
 * It uses a set of bases proven to be sufficient for all 64-bit integers, guaranteeing correct results
 * for the entire range of unsigned long long values.
 *
 * @param n The number to test for primality.
 * @return true if n is prime, false otherwise.
 *
 * @note Requires the helper function checkComposite to be defined, which checks if n is composite for a given base.
 */
bool isPrime(unsigned long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    // Write n-1 as d * 2^s, where d is odd.
    unsigned long long d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1; // d /= 2;
        s++;
    }

    // This set of bases is proven to be sufficient to deterministically test
    // all 64-bit integers. If the number passes the test for all these bases,
    // it is guaranteed to be prime.

    unsigned long long bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    // For numbers smaller than 3,317,044,064,279,371, a smaller set is sufficient.
    // For simplicity and correctness for the full range, we use the 12-base set.

    for (unsigned long long a : bases) {
        if (n == a) return true;
        if (checkComposite(n, a, d, s)) return false;
    }
    return true;
}

int main() {
    // A list of numbers to test
    unsigned long long test_numbers[] = {
        7,                           // Small prime
        97,                          // Prime
        137,                         // Prime
        561,                         // Carmichael number (composite)
        1105,                        // Carmichael number (composite)
        1000000007,                  // A common prime in competitive programming
        999999999999999989ULL,       // A large prime
        999999999999999999ULL,       // Composite (3^2 * 7 * ...)
        18446744073709551557ULL,     // A large prime close to the 64-bit limit
        18446744073709551615ULL      // Max unsigned long long (composite)
    };

    std::cout << "Running Miller-Rabin Primality Test...\n\n";
    for (unsigned long long n : test_numbers) {
        std::cout << n << " is " << (isPrime(n) ? "Prime" : "Composite") << ".\n";
    }

    return 0;
}