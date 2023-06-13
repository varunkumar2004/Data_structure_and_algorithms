#include <iostream>
using namespace std;

void func(int a, int b) {
    a++;
    b++;
    cout << a << " " << b << endl;
}

inline int getMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    int ans = getMax(a, b);
    cout << ans << endl;
    return 0;
}