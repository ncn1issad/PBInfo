// 100 points, 0s, C++11

#include <iostream>
using namespace std;

int a, b, ao = 0, bo = 0;

int main() {
    std::cin >> a >> b;
    int ca = a, cb = b;
    while (a) {
        ao = ao * 10 + a % 10;
        a /= 10;
    }
    while (b) {
        bo = bo * 10 + b % 10;
        b /= 10;
    }
    if (ao > bo) cout << ca;
    else if (bo > ao) cout << cb;
    else if (ca > cb) cout << cb;
    else cout << ca;
}