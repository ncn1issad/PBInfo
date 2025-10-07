

#include <iostream>

int n, k, m[20][20], l[20];

int main() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cin >> m[i][j];
    }
    for (int i = 0; i < k; i++)
        l[i] = m[k - 1][i];
    for (int i = 0; i < k; i++)
        m[k - 1][(i + 1) % k] = l[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << m[i][j] << ' ';
        std::cout << '\n';
    }
}