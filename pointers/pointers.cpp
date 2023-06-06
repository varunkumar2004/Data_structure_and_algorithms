#include <iostream>
using namespace std;

int main() {
    int num = 5;
    int *ptr = &num; // sizeof(ptr) -> 8 bits (always, doesn't depend on dataType)
    (*ptr)  = (*ptr) * 2;

    /*
    int *p = 0; // Pointer pointing to garbage address, bad practice
    int *s = 0; // null
    cout << *s; // Segmentation fault
    */

    cout << num << endl;
    return 0;
}