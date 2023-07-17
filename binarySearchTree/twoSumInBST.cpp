#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
#include <vector>
using namespace std;

void inOrderTraversal(Node* root, vector<int> &in) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
}

bool twoSuminBST(Node* root, int target) {
    vector<int> inorderVal;
    int i = 0, j = inorderVal.size() - 1;
    inOrderTraversal(root, inorderVal);

    while (i < j) {
        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target) {
            return true;
        } else if (sum > target) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

int main() {
    return 0;
}