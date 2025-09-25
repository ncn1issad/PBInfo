// 100 points, 0s, C++11

#include <iostream>

int mp = 7920;
int n, cnt;

int main() {
    bool v[mp];
    for (int i = 2; i < mp; i++) {
        v[i] = true;
    }
    std::cin >> n;

    for (int i = 2; i < mp; i++) {
        if (v[i]) {
            for (long long j = 1LL * i * i; j < mp; j += i) v[j] = false;
        }
    }

    for (int i = 0; cnt < n; i++) {
        if (v[i]) {
            std::cout << i << ' ';
            cnt++;
        }
    }
}