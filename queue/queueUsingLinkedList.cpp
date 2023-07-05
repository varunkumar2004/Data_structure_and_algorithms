#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node* insertAtTail(Node* &tail, int data) {
        return tail;
    }

    Node* deleteAtHead(Node* &head) {
        return head;
    }
};

class Queue {
private:
    Node* node;
    Node* front = node;
    Node* back = node;

public:
    Queue() {
    }

    Node* push(int data) {
        node->insertAtTail(back, data); 
    }

    bool isEmpty() {
        if (front == NULL) return true;
        return false;
    }

    Node* pop() {
        node->deleteAtHead(node);
    }
};

int main() {
    return 0;
}