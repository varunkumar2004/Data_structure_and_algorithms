#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
#include <vector>
using namespace std;

// Approach => using merged inorder of both BST's
vector<int> mergeArrays(vector<int> &a, vector<int> &b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        } else {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size()) {
        ans[k++] = a[i];
        i++;
    }

    while (j < b.size()) {
        ans[k++] = a[j];
        j++;
    }

    return ans;
}

vector<int> inorder(Node* root, vector<int> &ans) {
    if (root == NULL)
        return ans;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> mergeInorder(Node* root1, Node* root2) {
    vector<int> node1;
    vector<int> node2;
    vector<int> ans;
    
    inorder(root1, node1);
    inorder(root2, node2);
    ans = mergeArrays(node1, node2);
    return ans;
}

// Approach 2 => using linked list
void convertIntoSortedDLL(Node* root, Node* &head) {
    // base case
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
}

int countNode(Node* head) {
    int count = 0;
    Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->right;
    }
    
    return count;
}

Node* sortedLinkedListIntoBST(Node* &head, int n) {
    // base case
    if (n <= 0 || head == NULL)
        return NULL;
    
    Node* left = sortedLinkedListIntoBST(head, n/2);
    Node* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLinkedListIntoBST(head, n - n/2 - 1);
    return root;
}

int main() {
    return 0;
}