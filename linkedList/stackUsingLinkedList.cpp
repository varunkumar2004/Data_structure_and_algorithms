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
};

Node* insertAtTail(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

Node* deleteTail(Node* &head, Node* tail) { 
    Node* res = NULL;
    Node* temp = head;

    while(temp != NULL) {
        if(res == NULL) res = head;

        res = res->next;
        temp = temp->next;
    }

    res->next = NULL;
    tail = res;

    return head;
}

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

class Stack {
    int size, top;
    Node* head = NULL;
    Node* tail = NULL;

public:
    Stack(int size) {
        this->size = size;
        top = 0;
    }

    Node* push(int element) {
        if(top < size) {
            head = insertAtTail(head, tail, element);
            top++;
        }

        return head;
    }

    Node* pop() {
        if(top > 0) {
            head = deleteTail(head, tail);
        }

        return head;
    }

    Node* peek() {
        return tail;
    }

    bool isEmpty() {
        if(top == 0) return true;
        return false;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Stack st(4);

    st.push(1);
    st.push(2);
    st.push(3);
    head = st.push(4);

    tail = st.peek();
    head = st.pop();
    print(head);

    return 0;
}