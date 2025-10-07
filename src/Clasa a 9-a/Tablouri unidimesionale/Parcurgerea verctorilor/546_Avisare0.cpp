// 100 points, 0s, C++11  

#include <iostream>

int v[1000], n;

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    for (int i = 0; i < n; i++) {
        if (v[i] % v[n - 1] == 0) std::cout << v[i] << ' ';
    }
}