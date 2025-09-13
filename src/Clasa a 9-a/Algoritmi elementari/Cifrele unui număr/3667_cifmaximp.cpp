// 100 points, 0s, C++11

#include <iostream>
using namespace std;

short n, cnt;

int main() {
    cin >> n;
    for (short i = 0; i < n; i++) {
        int x;
        cin >> x;
        short cifmax = 0;
        while (x) {
            short c = x % 10;
            if (c > cifmax) {
                cifmax = c;
            }
            x /= 10;
        }
        if (cifmax % 2 == 1) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}