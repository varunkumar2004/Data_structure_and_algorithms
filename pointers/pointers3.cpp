#include <iostream>
using namespace std;

void update(int *p) {
    *p = (*p) * 2;
}

void increment(int **p) {
    ++(**p);
}

int main() {
    int i = 10;
    // update(&i);

    int first = 100;
    int *p = &first;
    int **q = &p;
    int second = ++(**q);
    int *r = *q;
    ++(*r);
    // cout << first << " " << second << endl;

    int num = 110;
    int *ptr = &num;
    increment(&ptr);
    cout << num << endl;
    return 0;
}