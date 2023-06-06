#include <iostream>
using namespace std;

// Euclid's Theorem
// gcd(a, b) = gcd(a - b, b) or gcd(a % b, b)
int gcd(int a, int b) {
    if(a == 0) return a;
    if(b == 0) return b;

    while (a != b) {
        if(a > b) {
            a = a - b;
        }else {
            b = b - a;
        }
    }

    return a;
}

// lcm(a, b) * gcd(a, b) = a * b
int lcm(int a, int b) {
    int result = gcd(a, b);
    int lcm = (a * b) / result;
    return lcm;
}

int main() {
    int a, b, hcf, lcm;
    cout << "enter value of a and b: ";
    cin >> a >> b;

    hcf = gcd(a, b);
    cout << "Ans: " << hcf << endl;
    return 0;
}