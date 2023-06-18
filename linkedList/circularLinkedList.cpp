#include <iostream>
#include <map>
using namespace std;

// Single Circular Linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "memory freed for value " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // Assuming that the element is present in linked list
        Node *curr = tail;
        while (curr->data != element)
            curr = curr->next;

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *tail, int value)
{
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    else
    {
        // Assuming that value is present in linked list
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = prev->next;
            curr = curr->next;
        }

        prev->next = curr->next;

        if (tail == curr)
            tail = prev;

        curr->next = NULL;
        delete curr;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertNode(tail, 5, 3);

    insertNode(tail, 3, 5);
    // insertNode

    return 0;
}