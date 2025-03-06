// https://leetcode.com/problems/longest-word-in-dictionary/description/

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
    string longest = "";

    int get_relative_pos(char ch) {
        return ch - 'a';
    }

    char get_character(int idx) {
        return idx + 'a';
    }

    bool is_leaf(Node *nd) {
        for(int i = 0; i < 26; i++) {
            if(nd->children[i] != NULL) return false;
        }
        return true;
    }

    void get_longest(Node *iter, string cur) {
        if(iter->EoW) {
            if(cur.size() > longest.size()) {
                longest = cur;
            } else if(cur.size() == longest.size()) {
                longest = min(longest, cur);
            }
        }

        if(is_leaf(iter)) {
            return;
        }

        for(int i = 0; i < 26; i++) {
            if(iter->children[i] != NULL and iter->EoW == true) {
                get_longest(iter->children[i], cur + get_character(i));
            }
        }
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

    string longest_word() {
        longest.clear();
        for(int i = 0; i < 26; i++) {
            if(root->children[i] != NULL) {
                string cur = "";
                cur += get_character(i);
                get_longest(root->children[i], cur);
            }
        }

        return longest;
    }
};

int main() {
    Trie tr;
    tr.insert("e");
    tr.insert("ey");
    tr.insert("eyj");
    tr.insert("d");
    cout << tr.longest_word() << endl;
}

