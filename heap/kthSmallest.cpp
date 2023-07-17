#include <iostream>
#include <queue>
using namespace std;

// Kth smallest elements in an array
// using priority queues => max heap
// Space Complexity => O(N)
int kthSmallest(int arr[], int l, int r, int k) {
    // r => ending index of array
    priority_queue<int> pq;

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i <= r; i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

// for kthLargest element => use min heap

int main() {
    return 0;
}