#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

class kQueue {
    int n, k;
    int *front, *rear, *arr;
    int free;
    int *next;

public:
    kQueue(int n, int k) {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        arr = new int[n];

        for (int i = 0; i < k; i++) {
            front[i] == -1;
            rear[i] == -1;
        }

        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
        }

        next[n - 1] = -1;

        free = 0;
    }

    bool isFull() {
        return (free == -1);
    }

    void push(int data, int qn) {
        // overflow 
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        // find first free index
        int i = free;
        free = next[i];

        if (isEmpty(qn)) {
            front[qn - 1] = i;
        } else {
            next[rear[qn - 1]] = i; 
        }

        next[i] = -1;

        rear[qn - 1] = i;

        arr[i] = data;
    }

    int pop(int qn) {
        // underflow
        if (front[qn] == -1) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        int index = front[qn - 1];
        front[qn - 1] = next[index];

        // update free slot
        next[index] = free;
        free = index;

        return arr[index];
    }

    bool isEmpty(int qn) {
        return (front[qn - 1] == -1);
    }
};

int main() {
    deque<int> q;
    return 0;
}