#include <iostream>
#include "binaryTreeClass.h"
#include <vector>
using namespace std;

void traverseLeft(Node* root, vector<int> &ans) {
    // base case
    if (root == NULL || (root->left == NULL && root->right == NULL)) 
        return;
    
    ans.push_back(root->data);

    if (root->left) {
         traverseLeft(root->left, ans);
    } else {
         traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans) {
    // base case
    if (root == NULL) 
        return;

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans) {
    // base case
    if (root == NULL || (root->left == NULL && root->right == NULL)) 
        return;

    if (root->right) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->right, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundary(Node* root) {
    vector<int> ans;
    if (root == NULL) 
        return ans;

    ans.push_back(root->data);

    // left boundary print
    traverseLeft(root->left, ans);

    // leaf node print
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // right boundary print
    traverseRight(root->right, ans);

    return ans;
}

int main() {
    return 0;
}