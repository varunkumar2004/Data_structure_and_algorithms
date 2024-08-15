#include <iostream>
#include "../binaryTree/binaryTreeClass.h"
using namespace std;

// Time Complexity => O(log n) 
// inorder of binary search tree is sorted => LNR
Node* insertIntoBST(Node* root, int d) {
    // base case
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minValue(Node* root) {    
    Node* temp = root;

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

Node* maxValue(Node* root) {    
    Node* temp = root;

    while (temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

int main() {
    Node* root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    return 0;
}