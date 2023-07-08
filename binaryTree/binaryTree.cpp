#include <iostream>
#include <queue>
#include "binaryTreeClass.h"
using namespace std;

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;

            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }

    }
}

void inOrder(Node* root) {
    // left node right
    // base case
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    // node left right
    // base case
    if (root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    // left right node
    // base case
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;
    cout << "Enter date for root: " ;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "enter left node for -> " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "enter right node for -> " << root->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;
    buildFromLevelOrder(root);

    /*
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    levelOrderTraversal(root);
    cout << endl;

    cout << "inOrder Traversal is: ";
    inOrder(root);
    cout << endl;

    cout << "preOrder Traversal is: ";
    preOrder(root);
    cout << endl;

    cout << "postOrder Traversal is: ";
    postOrder(root);
    */ 
   
    return 0;
}