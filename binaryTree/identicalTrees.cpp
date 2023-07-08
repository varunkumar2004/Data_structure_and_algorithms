#include <iostream>
#include "binaryTreeClass.h"
using namespace std;

bool compare(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) 
        return true;
    if (root1 == NULL && root2 != NULL) 
        return false;
    if (root2 == NULL && root1 != NULL) 
        return false;

    bool left = compare(root1->left, root2->left);
    bool right = compare(root1->right, root2->right);
    bool currValue = root1->data == root2->data;

    if (left && right && currValue) {
        return true;
    }

    return false;
}

int main() {
    return 0;
}