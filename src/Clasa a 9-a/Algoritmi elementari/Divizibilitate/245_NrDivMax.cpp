// 100 points, 0.072s, C++11

#include <iostream>

int n, max_i, c_cnt, m_cnt = 0;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        c_cnt = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                c_cnt++;
                if (j != i / j) {
                    c_cnt++;
                }
            }
        }
        if (c_cnt > m_cnt) {
            m_cnt = c_cnt;
            max_i = i;
        }
    }
    std::cout << max_i;
}