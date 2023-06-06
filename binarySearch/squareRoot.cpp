#include <iostream>
using namespace std;

// Finding Square Root of a number using Binary Search
long long int sqrtInteger(int n) {
    int s = 0, e = n - 1;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;

    while (s <= e) {
        long long int i = mid * mid;

        if (i > n) {
            e = mid - 1;
        }else if (i == n) {
            ans = mid;
            return ans;
        }else {
            ans = mid;
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++) {
        factor = factor / 10;

        for (double j = ans; j * j < n; j = j + factor) {
            ans = j;
        }
    }

    return ans;
}


int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout << "The Root is: " << morePrecision(n, 3, tempSol) << endl;
    return 0;
}