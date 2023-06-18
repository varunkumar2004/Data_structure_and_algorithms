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

Node *reverseInPackets(Node *&head, int k)
{
    if (head == NULL)
        return head;

    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        count++;
    }

    if (next != NULL)
        head->next = reverseInPackets(next, k);

    return prev;
}

int main()
{
    return 0;
}