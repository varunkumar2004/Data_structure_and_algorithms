#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

// find largest BST in binary tree that may or may not be BST
// Optimised Approach
class Info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

Info solve(Node* root, int &ans) {
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);
    Info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    
    if (left.isBST && right.isBST && (root->data > left.maxi) && (root->data < right.mini)) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    if (currNode.isBST) {
        ans = max(ans, currNode.size);
    }
}

int largestBST(Node* root) {
    int maxSize = 0;
    Info temp = solve(root, maxSize);
    return maxSize;
}

int main() {
    return 0;
}