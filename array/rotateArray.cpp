#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    vector<int> temp(arr.size());

    for(int i = 0; i < arr.size(); i++) {
        temp[(i + k) % arr.size()] = arr[i];
    }

    arr = temp;
    return arr;
}

void printArray(vector<int> arr) {
    cout << "Array is: ";

    for(int a: arr) {
        cout << a << " ";
    }
}

int main() {
    vector<int> arr = {1, 7, 9, 11};
    arr = rotateArray(arr, 2);
    printArray(arr);

    return 0;
}
