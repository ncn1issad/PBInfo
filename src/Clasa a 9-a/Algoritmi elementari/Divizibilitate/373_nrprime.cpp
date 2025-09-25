

#include <iostream>

int n;
bool v[1001];

int main() {
    for (int i = 2; i < n; i++) {
        v[i] = true;
    }
    std::cin >> n;

    //for (int i = 3; i * i <= n)

    for (int i = 0; i < n; i++) {
        if (v[i]) std::cout << i << ' ';
    }
}