#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

pair<int, int> solve(Node* root) {
    if (root == NULL) 
        pair<int, int> p = make_pair(0, 0);

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> result;
    result.first = root->data + left.second + right.second;
    result.second = max(left.first, right.second) + max(right.first, right.second);
    return result;
}

int getMaxSum(Node* root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main() {
    return 0;
}