/*
Determine the longest common prefix of some given words

Problem link: https://leetcode.com/problems/longest-common-prefix/description/
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

    char relChar(int idx) {
        return idx + 'a';
    }

    string longest_common_prefix_(Node* cur, string s, int prev_count) {
        int link_count = 0;
        int link = -1;
        for(int i = 0; i < 26; i++) {
            if(cur->children[i] != NULL) {
                link_count++;
                link = i;
            }
        }
        
        if(link_count != 1) return s;
        else {
            cur = cur->children[link];
            int cur_count = cur->prefix_count;

            if(cur_count == prev_count) {
                return longest_common_prefix_(cur, s + relChar(link), cur_count);
            } else {
                return s;
            }
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

    string longest_common_prefix() {
        string ret = longest_common_prefix_(root, "", root->prefix_count);
        return ret;
    }
};



int main() {
    TRIE trie;
    trie.insert("flower");
    trie.insert("fl");
    trie.insert("flight");
    string longest_prefix = trie.longest_common_prefix();
    cout << longest_prefix << endl;
    return 0;
}
