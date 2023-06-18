#include <iostream>
using namespace std;

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
};

void insertAtHead(Node *&head, int d)
{
    // Create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    tail->next = temp;
    tail = temp;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1;
        if (first != NULL)
            val1 = first->data;

        int val2;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        Node *temp = new Node(digit);
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }

    return ansHead;
}

Node *addTwoLinkedList(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);

    Node *ans = add(first, second);
    return ans;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    return 0;
}