#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

// balanced tree -> if (left - right) subtree <= 1 for every node
pair<bool, int> balance(Node* root) {
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = balance(root->left);
    pair<bool, int> right = balance(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool difference = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && difference) {
        ans.first = true;
    } else {
        ans.first = false;
    }

    return ans;
}

bool isBalanced(Node* root) {   // time complexity -> O(n^2)
    // base case
    if (root == NULL) {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool difference = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && difference) {
        return true;
    } 

    return false;
}

int main() {
    Node* root = NULL;
    return 0;
}