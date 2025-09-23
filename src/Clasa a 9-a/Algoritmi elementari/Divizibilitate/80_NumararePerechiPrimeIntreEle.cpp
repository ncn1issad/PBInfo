// 100 points, 0s, C++11

#include <iostream>

int a, b, cnt = 0;

bool PIE(int x, int y) {
    while (x && y) {
        if (x > y) x %= y;
        else y %= x;
    }
    if (x == 1) return true;
    if (y == 1) return true;
    return false;
} 

int main() {
    std::cin >> a;
    while (a != 0) {
        std::cin >> b;
        if (PIE(a, b)) cnt++;
        a = b;
    }
    std::cout << cnt;
}