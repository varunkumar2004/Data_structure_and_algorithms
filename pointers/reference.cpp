#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter memory: ";
    cin >> n;
    int arr[5]; // Static memory
    int *arr = new int[n]; // Dynamic memory allocation
    int **matrix = new int*[n];
    return 0;
}