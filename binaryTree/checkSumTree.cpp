#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

// sum Tree -> sum of all subtree left and subtree right nodes is equal to every node
pair<bool, int>  sumTree(Node* root) {
    // base case
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = sumTree(root->left);
    pair<bool, int> rightAns = sumTree(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = root->data == (leftAns.second + rightAns.second);

    pair<bool, int> ans;

    if (left && right && condn) {
        ans.first = true;
        ans.second = 2 * root->data;
    } else {
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root) {
    return sumTree(root).first;
}

int main() {
    return 0;
}