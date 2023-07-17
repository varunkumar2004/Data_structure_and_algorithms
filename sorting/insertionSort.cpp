#include <iostream>
#include <vector>
using namespace std;

// Time Complexity -> O(n)
// Stable Algorithm
void insertionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--) {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }

        arr[j + 1] = temp;
    }
}

int main() {
    vector<int> arr = {10, 1, 7, 4, 8, 2, 11};
    insertionSort(arr);

    for (auto i = 0; i < arr.size() - 1; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}