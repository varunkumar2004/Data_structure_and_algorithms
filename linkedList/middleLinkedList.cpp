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

int getLength(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

Node *findMiddle(Node *head)
{
    int len = getLength(head);
    int ans = (len / 2);
    int count = 0;

    Node *temp = head;

    while (count < ans)
    {
        temp = temp->next;
        count++;
    }

    return temp;
}

Node *getMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    if (head->next->next == NULL)
        return head->next;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;

        slow = slow->next;
    }

    return slow;
}

int main()
{
    return 0;
}