// 100 points, 0s, C++11

#include <iostream>

int n, x, ma = 0, mi = 1000000001;

int gcd(int x, int y) {
    while (x && y) {
        if (x > y) x %= y;
        else y %= x;
    }
    if(x) return x;
    else return y;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x > ma) ma = x;
        if (x < mi) mi = x;
    }
    std::cout << gcd(ma, mi);
}
