#include <iostream>
using namespace std;
#define PI 3.14 // Macro
#define min(a, b) (((a) < (b)) ? (a) : (b))

int i = 15;

void a(int& i) {
    char ch = 'a';
    cout << i << endl;
}

int main() {
    int r = 5;
    double area = PI * r * r;

    {
        int i = 2;
        cout << i << endl;
    }

    cout << ::i << endl;

    return 0;
}