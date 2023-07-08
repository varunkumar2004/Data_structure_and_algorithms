#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "---Enter the data---" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right: " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int height(Node* node) {
    if (node == NULL) return 0;

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}