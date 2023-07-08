#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

// flatten binary tree into linked list in place
// Approach 1 => using inorder traversal

// Approach 2 => using morris traversal
// PreOrder => NLR
void flatten(Node* &root) {
    Node* curr = root;

    while (curr == NULL) {
        if (curr->left) {
            Node* pred = curr->left;

            while (pred->right != NULL) {
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

int main() {
    return 0;
}