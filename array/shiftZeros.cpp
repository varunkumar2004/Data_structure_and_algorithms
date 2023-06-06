#include <iostream>
#include <vector>
using namespace std;

vector<int> shiftZeros(vector<int> arr) {
    int i = 0;
    int n = arr.size();

    for (int j = 0; j < n; i++) {
        if(arr[j] != 0) {
            swap(arr[j], arr[i]);
            i++;
        }
    }

    return arr;
}

void printArray(vector<int> arr) {
    int n = arr.size();

    cout << "Array A after merging B in sorted order : " << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    arr = shiftZeros(arr);
    printArray(arr);

    return 0;
}