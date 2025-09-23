// 100 points, 0.02s, C++11

#include <iostream>

int n, s = 0;

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
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (PIE(i, j)) s++;
        }
    }
    std::cout << s;
}