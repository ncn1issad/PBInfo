// 100 points, 0s, C++11

#include <iostream>

int a, b, cmmdc;

/**
 * @brief Calculates the greatest common divisor (GCD) of two integers using Stein's algorithm or Binary GCD algorithm.
 * 
 * This method only yielded 90 points because of time constraints
 * 
 * This function repeatedly subtracts the smaller number from the larger one until both numbers are equal.
 * The resulting value is the greatest common divisor (GCD) of the two input integers.
 * 
 * @param x First integer.
 * @param y Second integer.
 * @return int The greatest common divisor of x and y.
 */
int findCmmdc(int x, int y) {
    while (x != y){
        if (x > y) x -= y;
        else y -= x;
    }
    return x;
}

/**
 * @brief Calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
 * 
 * This function efficiently computes the GCD (also known as CMMDC in Romanian) of two non-negative integers x and y.
 * It repeatedly replaces the larger number by its remainder when divided by the smaller number until one of them becomes zero.
 * The non-zero value at the end is the GCD.
 * 
 * @param x First non-negative integer.
 * @param y Second non-negative integer.
 * @return int The greatest common divisor of x and y.
 */
int fastCmmdc(int x, int y) {
    while (x && y) {
        if (x > y) x %= y;
        else y %= x;
    }
    if (x) return x;
    else return y;
}

int main() {
    std::cin >> a >> b;
    cmmdc = fastCmmdc(a, b);
    for (int i = 1; i <= cmmdc; i++) {
        if (cmmdc % i == 0) std::cout << i << ' ';
    }
}