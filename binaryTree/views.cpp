#include <iostream>
#include "binaryTreeClass.h"
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<int> topView(Node* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> topNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd--)); 
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd++));
    }

    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans;
}

vector<int> bottomView(Node* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> topNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd--)); 
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd++));
    }

    for (auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans;
}

void solve(Node* root, vector<int> &ans, int lvl) {
    if (root == NULL)
        return;
    
    if (lvl == ans.size()) {
        ans.push_back(root->data);
    }

    solve(root->left, ans, lvl++);
    solve(root->right, ans, lvl++);
}

vector<int> leftView(Node* root) {   
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main() {
    return 0;
}