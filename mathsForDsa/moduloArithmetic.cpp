#include <iostream>
using namespace std;
#define LL long long;

// Modulo Formulas
// (a + b) % m = a % m + b % m
// a % m - b % m = (a - b) % m
// a % m * b % m = (a * b) % m

// Fast Exponentition
int modularExponentiation(long long x, unsigned int y, int p) {   
    int res = 1;

    x = x % p;

    if(x == 0) return 0;
    
    while(y > 0) {
        if(y & 1) { // Odd number   
            res = (res * x) % p;
        }

        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

int main() {
    return 0;
}