#include <iostream>
#include <cmath>
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

    ~Node()
    {
        delete next;
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

int getLength(Node *head)
{
    if (head == NULL)
        return 0;
    if (head->next == head)
        return 1;

    Node *curr = head;
    int count = 0;

    do
    {
        count++;
        curr = curr->next;
    } while (curr != head);

    return count;
}

Node *splitInHalf(Node *&head)
{
    Node *curr = head;
    int len = ceil(((double)getLength(head) / 2));
    int count = 1;

    while (count < len)
    {
        curr = curr->next;
        count++;
    }

    Node *head2 = curr->next;
    Node *curr2 = head2;
    curr->next = head;

    while (curr2->next != head)
        curr2 = curr2->next;

    curr2->next = head2;

    return head2;
}

void splitInHalfOptimised(Node *&head)
{
    // if (head == NULL)
    //     return NULL;
    // if (head->next = head)
    //     // return head;
    //     return;

    Node *slow = head;
    Node *fast = head;
    Node *head2 = NULL;

    do
    {
        slow = slow->next;
        fast = fast->next;

        if (fast != NULL)
            fast = fast->next->next;

        cout << "slow: " << slow->data << endl;
        cout << "fast: " << fast->data << endl;

    } while (slow != head && fast != head);

    fast->next = slow->next;
    head2 = slow->next;
    slow->next = head;

    // return head2;
}

void print(Node *&head)
{
    Node *temp = head->next;

    cout << head->data << " ";

    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *head2 = NULL;
    Node *tail = node1;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    // Making Circular linked list
    tail->next = head;

    int count = getLength(head);
    cout << "Count: " << count << endl;
    head2 = splitInHalf(head);
    // splitInHalfOptimised(head);

    print(head);
    print(head2);
    return 0;
}