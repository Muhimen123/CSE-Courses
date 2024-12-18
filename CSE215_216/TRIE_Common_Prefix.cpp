/*
Count how many times a prefix occurs

Sample Problem: https://vjudge.net/problem/SPOJ-ADAINDEX
*/
#include <iostream>
using namespace std;

struct Node {
    bool EoW;
    int prefix_count;
    Node *children[26];

    Node() {
        EoW = false;
        prefix_count = 0;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class TRIE {
    private:
    Node* root;

    int relPos(char ch) {
        return ch - 'a';
    }

    int relChar(int idx) {
        return idx + 'a';
    }

    void printTRIE_(Node* cur, string s = "") {
        if(cur->EoW == true) {
            cout << s << endl;
        }

        for(int i = 0; i < 26; i++) {
            if(cur->children[i] == NULL) continue;
            char ch = relChar(i);
            printTRIE_(cur->children[i], s + ch);
        }
    }

    public:
    TRIE() {
        root = new Node();
    }

    void insert(string s) {
        Node* iter = root;
        for(int i = 0; i < (int) s.size(); i++) {
            int j = relPos(s[i]);

            if(iter->children[j] == NULL) {
                iter->children[j] = new Node;
            }
            iter->prefix_count++;
            iter = iter->children[j];
        }

        iter->prefix_count++;
        iter->EoW = true;
    }

    bool search(string s) {
        Node* iter = root;
        for(int i = 0; i < (int) s.size(); i++) {
            int j = relPos(s[i]);
            if(iter->children[j] == NULL) return false;
            iter = iter->children[j];
        }

        return iter->EoW;
    }

    int get_prefix_count(string pref) {
        Node* iter = root;
        for(int i = 0; i < (int) pref.size(); i++) {
            int j = relPos(pref[i]);
            if(iter->children[j] == NULL) return 0;
            iter = iter->children[j];
        }

        return iter->prefix_count;
    }

    void printTRIE() {
        printTRIE_(root, "");
    }
};



int main() {
    TRIE trie;
    trie.insert("bobcat");
    trie.insert("bobcat");
    trie.insert("bobcat");
    trie.insert("bobdog");
    trie.insert("bobbird");
    trie.printTRIE();
    int cnt = trie.get_prefix_count("bobcat");
    cout << cnt << endl;
    return 0;

}
