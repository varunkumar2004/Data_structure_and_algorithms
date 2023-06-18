#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int d) {
    // Create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertInPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    // Creating a node for d;
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

Node *floydCycleFinding(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast != NULL)
            fast = fast->next->next;

        if (slow == fast)
            return slow;
    }

    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = floydCycleFinding(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deleteLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *start = getStartingNode(head);
    Node *temp = start;

    while (temp->next != start)
        temp = temp->next;

    temp->next = NULL;
}

void deleteSortedDuplicate(Node *&head)
{
    // Assume that the linked list is sorted
    if (head == NULL)
        return;

    Node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete nodeToDelete;
            curr = next_next;
        }
        else
            curr = curr->next;
    }
}

Node *deleteUnsortedDuplicate(Node *head)
{
    // Using map method -> also consider another solution to this problem
    if (head == NULL)
        return head;

    map<Node *, bool> visited;
    Node *curr = head;

    while (curr->next != NULL)
    {
        if (visited[curr] == true)
            delete curr;
        else
            curr = curr->next;
    }

    return head;
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
    Node *node1 = new Node(10);
    Node *head = node1; // Head pointed to node1
    Node *tail = node1; // Tail pointed to node1 --> optional

    // Insertion of new node at various positions
    insertAtTail(tail, 12);
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    // insertInPosition(head, tail, 3, 22);

    // Creating Looping Node
    // tail->next = head->next;

    // Loop present or not
    if (floydCycleFinding(head) != NULL)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle not present" << endl;

    // Loop start Node position
    // cout << "loops starts at: " << getStartingNode(head)->data << endl;

    // Delete looping node
    // deleteLoop(head);
    print(head);
    deleteSortedDuplicate(head);
    cout << "Deleted Duplicate" << endl;
    print(head);

    return 0;
}