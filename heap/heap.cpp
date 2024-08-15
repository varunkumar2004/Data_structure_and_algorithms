#include <iostream>
#include <queue>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) { 
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // delete root node from the heap binary tree
    void deleteFromHeap() {
        if (size == 0) {
            cout << "nothing to delete";
            return;
        }

        // step 1 => put last element into first index
        arr[1] = arr[size];
        size--;

        // step 2 => take root node to correct position
        int i = 1;
        while (i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if (rightIndex < size && arr[i] > arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;    
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    } else if (right < n && arr[largest] > arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    int size = n;
    while (size > 1) {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main() {
    priority_queue<int> pq; // priority_queue contains built-in max heap functionality

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "element at top: " << pq.top() << endl;
    pq.pop();

    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    return 0;
}