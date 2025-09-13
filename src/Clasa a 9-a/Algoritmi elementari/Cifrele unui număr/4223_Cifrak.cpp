// 100 points, 0s, C++11

#include <iostream>
using namespace std;

short n, k;

int s = -1;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y = 0;
        cin >> x;
        while (x) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (y % 10 == k) {
            if (s == -1) s = 0;
            while (y) {
                s += y % 10;
                y /= 10;
            }
        }
    }
    cout << s << '\n';
    return 0;
}