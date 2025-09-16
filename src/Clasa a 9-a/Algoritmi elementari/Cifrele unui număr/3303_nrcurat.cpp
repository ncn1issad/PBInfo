// 100 points, 0s, C++11

#include <fstream>
using namespace std;

ifstream IN("nrcurat.in");
ofstream OUT("nrcurat.out");

int x, xo, xu, cx;

int main() {
    while (IN >> x) {
        xo = 0;
        xu = 0;
        cx = x;
        while (x) {
            xo = xo * 10 + x % 10;
            xu = xu * 10 + 9;
            x /= 10;
        }
        xu -= cx;
        if (xu == xo) OUT << "1 ";
        else OUT << "0 ";
    }
    return 0;
}