#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    // base case
    if (root == NULL) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum += root->data;

    solve(root->left, sum, maxSum, len++, maxLen);
    solve(root->right, sum, maxSum, len++, maxLen);
}

int sumOfLongRootToLeaf(Node* root) {
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = 0;

    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}

int main() {
    return 0;
}