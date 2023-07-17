#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
#include <vector>
using namespace std;

// Balanced BST => if difference of height of left and right subtree is not greator than 1
// Approach => using inorder traversal, bisect it into subtrees
void inorder(Node* root, vector<int> &ans) {
    if (root == NULL)
        return;
    
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

Node* inorderToBST(int s, int e, vector<int> &ans) {
    // base case
    if (s > e) 
        return NULL;

    int mid = (s + e)/ 2;
    Node* root = new Node(ans[mid]);
    root->left = inorderToBST(s, mid - 1, ans);
    root->right = inorderToBST(mid + 1, e, ans);
    return root;
}

Node* balancedBST(Node* root) {
    vector<int> ans;
    inorder(root, ans);
    return inorderToBST(0, ans.size() - 1, ans);
}

int main() {
    return 0;
}