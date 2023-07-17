#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

Node* LCAinBST(Node* root, Node* P, Node* Q) {
    while (root != NULL) {
        if (root->data < P->data && root->data < Q->data)
            root = root->right;
        else if (root->data > P->data && root->data > Q->data) 
            root = root->left;
        else 
            return root;
    }
}

int main() {
    return 0;
}