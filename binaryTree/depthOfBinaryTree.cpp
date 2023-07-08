#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

int binaryTreeHeight(Node* node) {
    if (node == NULL) return 0;

    int left = binaryTreeHeight(node->left);
    int right = binaryTreeHeight(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

int main() { 
    Node *root = new Node(1);
    buildTree(root);
    return 0;
}