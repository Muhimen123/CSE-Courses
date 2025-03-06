#include <iostream>
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

class TRIE {
    private:
    Node* root;

    int relPos(char ch) {
        return ch - 'a';
    }

    char relChar(int idx) {
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

    bool can_delete(Node* cur) {
        if(cur->EoW) return false;
        for(int i = 0; i < 26; i++) {
            if(cur->children[i] != NULL) return false;
        }
        return true;
    }

    void remove_node(Node* cur, Node *parent, char link) {
        int j = relPos(link);
        parent->children[j] = NULL;
        delete cur; 
    }

    void erase_(Node* cur, Node* prev, int idx, string s) {
        int sz = s.size();

        if(idx == sz) {
            if(!can_delete(cur)) {
                cur->EoW = false;
                return;
            } else {
                if(can_delete(cur) and prev != NULL) {
                    remove_node(cur, prev, s[idx-1]);
                }
            }
            return;
        }

        int j = relPos(s[idx]);
        erase_(cur->children[j], cur, idx + 1, s);
        if(can_delete(cur) and prev != NULL) {
            remove_node(cur, prev, s[idx-1]);
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

            iter = iter->children[j];
        }
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

    void erase(string s) {
        if(search(s) == false) return;
        erase_(root, NULL, 0, s);
    }

    void printTRIE() {
        printTRIE_(root, "");
    }
};



int main() {
    TRIE trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("applet");
    trie.insert("cat");
    trie.insert("dogandcat");
    trie.insert("catanddog");
    trie.printTRIE();

    trie.erase("applet");
    trie.erase("cat");
    trie.erase("dog");
    cout << "---" << endl;
    trie.printTRIE();

    bool res = trie.search("cat");
    cout << res << endl;
    return 0;
}
