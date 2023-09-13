#include <iostream>
#include <vector>
using namespace std;

// Time Complexity -> O(n^2)
// Suitable for small arrays
// Unstable Algorithm -> doesn't preserve order of sort keys
void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) minIndex = j; 
        }

        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    vector<int> arr = {4, 2, 1, 3};
    selectionSort(arr, 4);

    for (auto i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}