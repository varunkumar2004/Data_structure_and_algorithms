#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

void findPreSuc(Node* root, Node* &pre, Node* &suc, int key) {
    if (root == NULL) {
        return;
    }

    if (root->data == key) {
        if (root->left != NULL) {
            Node* temp = root->left;

            while (temp->right) {
                temp = temp->right;
            }

            pre = temp;
        }

        if (root->right != NULL) {
            Node* temp = root->right;

            while (temp->left) {
                temp = temp->left;
            }

            suc = temp;
        }
    }

    if (root->data > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }

    return;
}

int main() {
    return 0;
}