#include <iostream>
#include <vector>
using namespace std;

// Approach 1 => using loops 
// Time Complexity => O(M*N)
// Space Complexity => O(1) (if string ans is ignored)
string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";

    // for traversing all char of fifst string
    for (int i = 0; i < arr[0].length(); i++) {
        char ch = arr[0][i];
        bool match = true;

        for (int j = 1; j < n; j++) {
            // not match
            if (arr[j].size() < i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }

        if (match == false) {
            break;
        } else {
            ans.push_back(ch);
        }
    }

    return ans;
}

// Approach 2 => using trie
// if child count is one only then add it in the string
// Time Complexity => O(M*N)
// Space Complexity => O(M*N)
class trieNode {
public:
    char data;
    trieNode* children[26];
    int childCount;
    bool isTerminal;

    trieNode(char data) {
        this->data = data;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        childCount = 0;
        isTerminal = false;
    }
};

class trie {
public:
    trieNode* root;

    trie (char ch) {    
        root = new trieNode(ch);
    }

    void insertUtil(trieNode* root, string word) {
        // base case
        if (word.length() == 0) {   
            root->isTerminal = true;
            return;
        }

        // assuming the word in CAPS
        int index = word[0] - 'a';
        trieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
            root->childCount++;
        } else {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (root->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            } else {
                break;
            }

            if (root->isTerminal) {
                break;
            }
        }

    }
};

string longestCommonPrefixTrie(vector<string> &arr, int n) {
    trie* t = new trie('/0');

    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}

int main() {
    return 0;
}