#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    bool EoW;
    int suffix_count;
    node* children[26];

    node() {
        EoW = false;
        suffix_count = 0;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class TRIE_Common_Suffix {
private:
    node* root;
    
    int relPos(char ch) {
        return ch - 'a';
    }

    char relChar(int idx) {
        return idx + 'a';
    }

    void printTRIE_(node* cur, string s) {
        if(cur->EoW == true) {
            reverse(s.begin(), s.end());
            cout << s << endl;
        } 
        for(int i = 0; i < 26; i++) {
            if(cur->children[i] != NULL) {
                char ch = relChar(i);
                printTRIE_(cur->children[i], s + ch);
            }
        }
    }

public:
    TRIE_Common_Suffix() {
        root = new node();
    }

    void insert(string s) {
        reverse(s.begin(), s.end());
        node* iter = root;
        for(int i = 0; i < (int) s.size(); i++) {
            int j = relPos(s[i]);
            if(iter->children[j] == NULL) {
                iter->children[j] = new node();
            }
            iter->suffix_count++;
            iter = iter->children[j];
        }

        iter->suffix_count++;
        iter->EoW = true;
    }

    void printTRIE() {
        printTRIE_(root, "");
    }

    int get_suffix_count(string pref) {
        reverse(pref.begin(), pref.end());
        node* iter = root;
        for(int i = 0; i < (int) pref.size(); i++) {
            int j = relPos(pref[i]);
            if(iter->children[j] == NULL) return 0;
            iter = iter->children[j];
        }

        return iter->suffix_count;
    }

    bool search(string s) {
        reverse(s.begin(), s.end());
        node* iter = root;
        for(int i = 0; i < (int) s.size(); i++) {
            int j = relPos(s[i]);
            if(iter->children[j] == NULL) return false;
            iter = iter->children[j];
        }
        return iter->EoW;
    }
};

int main() {
    TRIE_Common_Suffix trie;
    trie.insert("xyzabc");
    trie.insert("asdfabc");
    trie.insert("qwertyabc");
    trie.insert("ahoabcc");
    trie.insert("trieaabc");
    trie.insert("asdfbc");

    int res = trie.get_suffix_count("abc");
    cout << res << endl;
    return 0;
}


 
