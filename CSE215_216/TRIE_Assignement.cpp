#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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
        return ch - 'A';
    }

    char relChar(int idx) {
        return idx + 'A';
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
    
    // string and the number of occurance
    pair<int, string> commonPrefix_(Node* cur, int prev_count, string str) {
        if(cur->prefix_count != prev_count and prev_count != -1) {
            return make_pair(prev_count, str);
        }

        bool has_link = false;
        pair<int, string> output = make_pair(0, "");
        for(int i = 0; i < 26; i++) {
            if(cur->children[i] != NULL) {
                has_link = true;
                pair<int, string> tmp;
                tmp = commonPrefix_(cur->children[i], cur->prefix_count, str + relChar(i));
                output = comparePairs(output, tmp);
            }
        }
        if(!has_link) return make_pair(prev_count, str);        
        else return output;
    }

    pair<int, string> comparePairs(pair<int, string> p1, pair<int, string> p2) {
        pair<int, string> maxPair = p1;
        if(p2.first > maxPair.first) maxPair = p2;
        else if(p2.first == maxPair.first and p2.second.size() > maxPair.second.size()) maxPair = p2;

        return maxPair;
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

        iter->EoW = true;
    }

    void printTRIE() {
        printTRIE_(root, "");
    }

    string commonPrefix() {
        pair<int, string> ret = make_pair(0, "");

        for(int i = 0; i < 26; i++) {

            if(root->children[i] != NULL) {
                string st = "";
                st += relChar(i);
                pair<int, string> output =  commonPrefix_(root->children[i], -1, st);
                ret = comparePairs(ret, output);
            }
        }
        return ret.second;
    }
};


int main() {
    TRIE trie;
    int query;
    cin >> query;    
    while(query--) {
        int op;
        cin >> op;

        if(op == 1) {
            string str;
            cin >> str;
            trie.insert(str);
        } else {
            string ans = trie.commonPrefix();
            cout << ans << endl;
        }
    }
    return 0;
}
