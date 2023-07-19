#include <iostream>
#include <vector>
using namespace std;

// Question => display all records with a specific prefix 

// Approach 1 => using trie
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

    void printSuggestions(trieNode* curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            trieNode* next = curr->children[ch - 'a'];

            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        trieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];

            prefix.push_back(lastch);

            // check for last ch
            trieNode* curr = prev->children[lastch - 'a'];

            if (curr == NULL) break;

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr) {
    trie* t = new trie('\0'); 

    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestions(queryStr);
}

int main() {
    return 0;
}