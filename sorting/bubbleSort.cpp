#include <iostream>
#include <vector>
using namespace std;

// Bubble sort
void bubbleSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {7, 6, 2, 9, 8};
    bubbleSort(arr, 5);

    for (auto i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}