#include <iostream>
#include <vector>
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

void insertAtTail(Node *&tail, int d)
{
    Node *newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

// Approach 1
bool checkPalindrome1(vector<int> vec)
{
    int s = 0, e = vec.size() - 1;

    while (s <= e)
    {
        if (vec[s] != vec[e])
            return false;

        s++;
        e--;
    }

    return true;
}

bool isPalindrome1(Node *head)
{
    vector<int> vec;
    Node *temp = head;

    while (temp != NULL)
    {
        vec.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome1(vec);
}

// Approach 2
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

Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

bool isPalindrome2(Node *head)
{
    if (head->next == NULL)
        return true;

    Node *middle = getMid(head);

    Node *temp = middle->next;
    middle->next = reverse(temp);

    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    }

    temp = middle->next;
    middle->next = reverse(temp);

    return true;
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
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 10);

    print(head);
    bool result = isPalindrome2(head);
    cout << result << endl;
    return 0;
}