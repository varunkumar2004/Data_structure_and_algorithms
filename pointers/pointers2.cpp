#include <iostream>
using namespace std;

int main() {
    int arr[10];
    for(int i = 0; i < 10; i++) {   
        arr[i] = i+1;
    }

    int *ptr = &arr[0];
    cout << "First location address: " << arr << endl;
    cout << "First location address: " << &arr << endl;
    cout << "First value: " << *ptr << endl;
    return 0;
}