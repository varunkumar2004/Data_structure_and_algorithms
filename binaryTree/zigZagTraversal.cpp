#include <iostream>
#include "binaryTreeClass.h"
#include <vector>
#include <queue>
using namespace std;

vector<int> zigZagTraversal(Node* root) {
    vector<int> result;
    if (root == NULL)  
        return result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        // level process
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left) {
                q.push(frontNode->left);
            }

            if (frontNode->right) {
                q.push(frontNode->right);
            }
        }

        // direction change
        leftToRight = !leftToRight;

        for (auto i: ans) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    return 0;
}