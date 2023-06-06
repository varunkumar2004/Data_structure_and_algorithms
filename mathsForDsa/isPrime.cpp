#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;

    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int primeCount(int n) {
    int count = 0;

    for(int i = 2; i < n; i++) {
        if(isPrime(n)) count++;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if(isPrime(n) == 1) {
        cout << "Prime Number" << endl;
    }else {
        cout << "Not Prime Number" << endl;
    }

    return 0;
}