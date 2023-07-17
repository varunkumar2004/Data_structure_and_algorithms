#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

Node* minValue(Node* root) {    
    Node* temp = root;

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

Node* deleteNode(Node* root, int val) {
    // base case
    if (root == NULL)
        return root;
    
    if (root->data == val) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL) {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }

    } else if (root->data > val) {
        root->left = deleteNode(root->left, val);
    } else {
        root->right = deleteNode(root->right, val);
    }
}

int main() {
    return 0;
}