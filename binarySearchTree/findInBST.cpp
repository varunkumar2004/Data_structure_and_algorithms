#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

// iterative
bool isPresent(Node* root, int x) { 
    Node* temp = root;

    while (temp != NULL) {
        if (temp->data == x)
            return true;
        
        if (temp->data > x)
            temp = temp->left;
        else 
            temp = temp->right;
    }
}

// recursive space complexity => O(H)
bool isInBinarySearchTree(Node *root, int target) {
    if (root == NULL) 
        return false;

    if (root->data == target)
        return true;
    
    if (root->data > target) {
        return isInBinarySearchTree(root->left, target);
    }

    return isInBinarySearchTree(root->right, target);
}
                        
int main() {
    return 0;
}