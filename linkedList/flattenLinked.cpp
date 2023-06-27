#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* child;

    node(int data) {
        this->data = data;
    }
};

node* createRightNode(node *&tail, int data) {
    node* temp = new node(data);
    if(tail == NULL) tail = temp;

    tail->next = temp;
    temp->next = NULL;
    temp->child = NULL;
    tail = temp;

    return tail;
}

node* createChildNode(node *&tail, int data) {
    node* temp = new node(data);
    tail->child = temp;
    tail->next = NULL;

    return tail;
}

node* merge(node* a, node* b) {
    if (a == NULL)
        return b;
        
    if (b == NULL)
        return a;
        
    node* result;
 
    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    }
 
    else {
        result = b;
        result->child = merge(a, b->child);
    }
    result->next = NULL;
    return result;
}

node* flatten(node* head) {
    if(head == NULL || head->next == NULL) return head;

    head->next = flatten(head->next);

    head = merge(head, head->next);
    return head;
}

void print(node* head) {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    node* node1 = new node(1);
    node* head1 = node1;
    node* tail1 = node1;

    node* node2 = new node(10);
    node* head2 = node2;
    node* tail2 = node2;

    // createRightNode(tail1, 2);
    // createRightNode(tail1, 3);
    // print(head1);

    // createChildNode(head1, 10);
    // createChildNode(head1->child, 20);
    // flattenLinkedList(head);

    createRightNode(tail2, 20);
    createRightNode(tail2, 30);

    createChildNode(head2, 100);
    createChildNode(head2->child, 200);
    createChildNode(head2->child->child, 300);

    flatten(head2);
    print(head2);
    return 0;
} 