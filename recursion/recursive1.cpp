#include <iostream>
using namespace std;

int fact(int n) {
    // base case 
    if(n == 0) return 1;

    int result = n * fact(n - 1);
    return result;
}

int power(int x, int n) {
    if(n == 0) return 1;

    int result = x * power(x, n - 1);
    return result;
}

void print(int n) {
    if(n == 0) return ;


    cout << n << endl;
    print(n - 1);
}

int main() {
    int x, n;
    cout << "Enter number and power: ";
    cin >> x >> n;

    n = power(x, n);
    print(n);
    cout << n << endl;
    return 0;
}