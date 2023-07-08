#include <iostream>
#include <queue>
#include "binaryTreeClass.h"
using namespace std;

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

void inOrder(Node* root, int &count) {
    // base case
    if (root == NULL) {
        return;
    }

    inOrder(root->left, count);
    
    // leaf condition
    if (root->left == NULL && root->right == NULL) {
        count++;
    }

    inOrder(root->right, count);
}

int noOfLeafNodes(Node* root) {
    int count = 0;
    inOrder(root, count);
    return count;
}

int main() {
    Node* root = NULL;
    buildFromLevelOrder(root);
    return 0;
}