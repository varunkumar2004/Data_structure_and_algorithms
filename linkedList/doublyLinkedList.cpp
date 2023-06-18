#include <iostream>
using namespace std;

// Doubly linked list
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "memory free for value " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr->next = NULL)
        {
            tail = prev;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << head->data << endl;
    // cout << tail->data << endl;
}

int getLength(Node *head)
{
    int count = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head, tail);
    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 13);
    insertAtHead(head, tail, 8);
    insertAtTail(tail, tail, 25);

    print(head, tail);

    insertAtPosition(head, tail, 2, 233);
    print(head, tail);
    return 0;
}