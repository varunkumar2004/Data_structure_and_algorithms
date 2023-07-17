#include <iostream>
#include <vector>
using namespace std;

// 1 based indexing
void heapify(vector<int> arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    } else if (right < n && arr[largest] > arr[right]) {
        right = largest;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // step 1 => merger two vectors into a new vector
    vector<int> ans;

    for (auto i: a) {
        ans.push_back(i);
    }

    for (auto i: b) {
        ans.push_back(i);
    }

    // step 2 => build heap from merged heap
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(ans, n, i); 
    }

    return ans;
}

int main() {
    return 0;
}