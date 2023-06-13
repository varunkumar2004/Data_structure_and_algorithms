#include <iostream>
using namespace std;

// Types of LinkedList
//  -> singly linked
//  -> doubly linked
//  -> circular linked
//  -> circular doubly linked

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    // Create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void inserAtTail()
{
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1; // Head pointed to node1
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    print(head);
    return 0;
}