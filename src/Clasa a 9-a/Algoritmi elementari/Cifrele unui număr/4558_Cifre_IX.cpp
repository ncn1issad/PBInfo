// 100 points, 0s, C++11

#include <iostream>
using namespace std;

int n;

bool isCresc = true, isDesc = true, isEqual = true;

int main() {
    cin >> n;

    int lastDigit = n % 10;
    n /= 10;

    while (n) {
        int currentDigit = n % 10;
        n /= 10;

        if (!(currentDigit < lastDigit)) {
            isCresc = false;
        } 
        if (!(currentDigit > lastDigit)) {
            isDesc = false;
        } 
        if (currentDigit != lastDigit) {
            isEqual = false;
        }

        lastDigit = currentDigit;
    }

    if (isCresc) {
        cout << "strict crescatoare";
    } else if (isDesc) {
        cout << "strict descrescatoare";
    } else if (isEqual) {
        cout << "egale";
    } else {
        cout << "neordonate";
    }
    return 0;
}