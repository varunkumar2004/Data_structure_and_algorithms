#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
#include <vector>
using namespace std;

// Approach => store inorder and convert into linkedlist 
void inorderTraversal(Node* root, vector<Node*> &ans) {
    if (root == NULL) return;

    inorderTraversal(root->left, ans);
    ans.push_back(root);
    inorderTraversal(root->right, ans);    
}

Node* bstIntoLinkedList(Node* &root) {
    vector<Node*> ans;
    inorderTraversal(root, ans);
    int size = ans.size(), count = 0;
    Node* newNode = new Node(root->data);

    for (int i = 0; i < size - 1; i++) {
        ans[i]->left = NULL;
        ans[i]->right = ans[i + 1];
    }

    ans[size - 1]->left = NULL;
    ans[size - 1]->right = NULL;
    return newNode;
}

int main() {
    return 0;
}