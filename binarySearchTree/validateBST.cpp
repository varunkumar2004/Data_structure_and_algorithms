#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

// inorder traversal is sorted
// Approach => taking range 
bool isBST(Node* root, int min, int max) { 
    if (root == NULL)
        return true;

    if (root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->left, root->data, max);
        return left && right;
    } 

    return false;
}   

bool validBst(Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    return 0;
}