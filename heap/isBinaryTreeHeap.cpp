#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

// check for Complete Binary Tree
// check for max heap
int countNodes(Node* root) {
    if (root == NULL) 
        return 0;
    
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root, int index, int count) { 
    if (root == NULL)
        return true;

    if (index >= count) {
        return false;
    } else {
        bool left = isCBT(root->left, 2 * index + 1, count);
        bool right = isCBT(root->right, 2 * index + 2, count);

        return left && right;
    }
}

bool isMaxOrder(Node* root) {
    if (root->right == NULL && root->left == NULL) {
        return true;
    }

    if (root->right == NULL) {
        return (root->data > root->left->data);
    } else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        if (left && right && (root->data > root->left->data && root->data > root->right->data)) {
            return true;
        } else {
            return false;
        }
    }
}

bool isHeap(Node* root) {
    int index = 0;
    int totalCount = countNodes(root);
    if (isCBT(root, index, totalCount) && isMaxOrder(root)) {
        return true;
    }

    return false;
}

int main() {
    return 0;
}