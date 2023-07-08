#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

int height(Node* node) {
    if (node == NULL) return 0;

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

// diameter -> longest path between any two ending nodes
pair<int, int> diameterFast(Node* root) {
    if (root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int diameter(Node* root) {
    return diameterFast(root).first;
}

int main() {
    return 0;
}