#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool EoW;
    Node *children[26];

    Node() {
        EoW = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
private:
    Node *root;

    int get_relative_pos(char ch) {
        return ch - 'a';
    }

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *iter = root;
        for(auto chr: word) {
            int idx = get_relative_pos(chr);
            if(iter->children[idx] == NULL) {
                iter->children[idx] = new Node;
            }
            iter = iter->children[idx];
        }
        iter->EoW = true;
    }
    
    bool search(string word) {
        Node *iter = root;
        for(auto chr: word) {
            int idx = get_relative_pos(chr);
            if(iter->children[idx] == NULL) {
                return false;
            }

            iter = iter->children[idx];
        }    

        return iter->EoW;
    }
    
    bool startsWith(string prefix) {
        Node *iter = root;
        for(auto chr: prefix) {
            int idx = get_relative_pos(chr);
            if(iter->children[idx] == NULL) return false;
            iter = iter->children[idx];
        }
        return true; 
    }
};

int main() {
    Trie tr;
    tr.insert("apple");
    tr.insert("bob");
    cout << tr.startsWith("app") << endl;
}

