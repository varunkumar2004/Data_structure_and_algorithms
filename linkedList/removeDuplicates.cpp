#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node(int data) {
        this->val = data;
        next = NULL;
    }
};

// remove duplicates from sorted linked list
void removeDuplicates(Node* &head) {
    Node* curr = head;

    while(curr != NULL) {
        if (curr->val == curr->next->val) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }   
}

int main()
{
    return 0;
}