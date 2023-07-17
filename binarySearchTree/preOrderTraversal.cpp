#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
#include <vector>
using namespace std;

// BST from preorder
// Approach 1 => sorting preorder (inorder) and then creating BST {time Complexity -> O(N logN)}

// Approach 2 => Time Complexity O(N)
Node* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    if (i >= preorder.size())
        return NULL;

    if (preorder[i] < mini || preorder[i] > maxi) {
        return NULL;
    }

    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

Node* bstFromPreorder(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    solve(preorder, mini, maxi, i);
}

int main() {
    return 0;
}