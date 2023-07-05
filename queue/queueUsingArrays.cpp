#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        if (front == rear) return true;
        return false;   
    }

    void enqueue(int data) { // push function
        if (rear == size) 
            cout << "Queue is full!" << endl;

        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() { // pop function
        if (front == rear) return -1;

        int ans = arr[front];
        arr[front] = -1;
        front++;
         
        if (front == rear) {
            front = 0;
            rear = 0;
        }

        return ans;
    }

    int front() {
        if (front == rear) return -1;
        else {
            return arr[front];
        }
    }
};

int main() {
    return 0;
}