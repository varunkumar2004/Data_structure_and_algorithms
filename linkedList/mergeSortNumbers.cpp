#include <iostream>
using namespace std;

// Sort linked list containing only -> 0s, 1s and 2s
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
        this->next = NULL;
        // delete next;
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

Node *sortApproach1(Node *&head)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCount++;

        if (temp->data == 1)
            oneCount++;

        if (temp->data == 2)
            twoCount++;

        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }

        temp = temp->next;
    }

    return head;
}

Node *sortApproach2(Node *&head)
{
    // data replacement not allowed
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    while (curr != head)
    {
        int value = curr->data;

        if (value == 0)
            insertAtTail(zeroTail, curr);
        else if (value == 1)
            insertAtTail(oneTail, curr);
        else if (value == 2)
            insertAtTail(twoTail, curr);

        curr = curr->next;
    }

    // merge 3 linked list
    if (oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

Node *solve(Node *&first, Node *&second)
{
    // if only element is present
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data > curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node *mergeSortedLinkedList(Node *&first, Node *&second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
        return solve(first, second);

    return solve(second, first);
}

void print(Node *head)
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
    Node *node1 = new Node(5);
    Node *node2 = new Node(5);
    Node *head1 = node1;
    Node *head2 = node2;

    // creating first linked list
    insertAtHead(head1, 3);
    insertAtHead(head1, 1);

    // creating second linked list
    insertAtHead(head2, 4);
    insertAtHead(head2, 2);

    head1 = mergeSortedLinkedList(head1, head2);
    print(head1);
    return 0;
}