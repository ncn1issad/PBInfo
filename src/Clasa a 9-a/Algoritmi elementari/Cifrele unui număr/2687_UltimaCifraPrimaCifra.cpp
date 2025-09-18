// 100 points, 0s, C++11

#include <iostream>
using namespace std;

int n, l, c, cc;

int main(){
    cin >> n >> l;
    for (int i = 1; i < n; i++) {
        cin >> c;
        cc = c;
        while (cc > 9) {
            cc /= 10;
        }
        if (l % 10 == cc) cout << l << ' ' << c << '\n';
        l = c;
    }
}