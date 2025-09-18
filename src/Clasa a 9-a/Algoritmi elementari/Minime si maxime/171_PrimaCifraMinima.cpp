// 100 points, 0s, C++11

#include <iostream>
using namespace std;

int n, c = 10, ctr_e = 0, max_e;

int main() {
    cin >> n;
    int v[n], vc[n], ve[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vc[i] = v[i];
    }
    for (int i = 0; i < n; i++) {
        while (vc[i] > 9) {
            vc[i] /= 10;
        }
        if (vc[i] < c) {
            c = vc[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (vc[i] == c) {
            ve[ctr_e] = v[i];
            ctr_e++;
        }
    }
    max_e = ve[0];
    for (int i = 1; i < ctr_e; i++) {
        if (ve[i] > max_e) max_e = ve[i];
    }
    cout << max_e;
}