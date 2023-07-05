#include <iostream>
#include <queue>
using namespace std;

class Deque {
    int *arr;
    int front, rear;
    int size;

public:
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool push_front(int x) {
        // check full
        if ((front == 0 && rear == -1) || ((front != 0) && rear == (front - 1) % (size - 1))) {
            return false;
        } else if (front == -1) {
            front = rear = 0;
        } else if (front == 0 && rear != size - 1) {
            front = size - 1;
        } else {
            front--;
        }

        arr[front] = x;
        return true;
    }

    bool push_rear(int x) {
        // check full
        if ((front == 0 && rear == -1) || ((front != 0) && rear == (front - 1) % (size - 1))) {
            return false;
        } else if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    int pop_front() {
        if (front == -1) {
            return -1;
        } 

        int ans = arr[front];
        arr[front] = -1;
        
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;  // to maintain cyclic nature
        } else {
            front++;
        }

        return ans;
    }

    int pop_rear() {
        if (front == -1) {
            return -1;
        } 

        int ans = arr[rear];
        arr[rear] = -1;
        
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;  // to maintain cyclic nature
        } else {
            rear--;
        }

        return ans;
    }

    bool isEmpty() {
        if (front == -1) return true;
        return false;
    }

    int get_front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int get_rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    return 0;
}