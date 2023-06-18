#include <iostream>
#include <unordered_map>
using namespace std;

// Cpoy linked list with random pointers
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *copyList(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;

    // Creating a clone of linked list
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // Creating a map
    unordered_map<Node *, Node *> oldToNew;

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        oldToNew[temp] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode->random = oldToNew[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

Node *cloneList2(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;

    // Copying clone linked list
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    Node *originalNode = head;
    Node *cloneNode = head;
    Node *next = originalNode->next;
    originalNode->next = cloneNode;
    originalNode = next;

    return head;
}

int main()
{
    return 0;
}