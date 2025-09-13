// 100 points, 0s, C++11

#include <iostream>

long long n, p = 1;

bool isValid = false; // To handle the case when all digits are k

short k;

int main() {
    std::cin >> n >> k;
    while (n) {
        int c = n % 10;
        if (c != k) {
            p *= c; 
            isValid = true;
        }
        n /= 10;
    }
    if (!isValid) p = 0;
    std::cout << p << '\n';
    return 0;
}