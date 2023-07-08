#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

// Morris traversal
void morrisTraversal(Node* root) {
    Node* current;
    Node* pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        } else {
            pre = current->left;

            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    return 0;
}