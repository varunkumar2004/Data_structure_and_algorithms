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

Node *reverse1(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *tempHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return tempHead;
}

void reverse(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    if (head == NULL || head->next == NULL)
        return head;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
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
    Node* head = new Node(1);
    Node* tail = head;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);

    head = reverseLinkedList(head);
    print(head);
    return 0;
}