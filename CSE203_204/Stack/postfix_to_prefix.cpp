#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node *next;
};


class Stack
{
private:
    Node *head;

public:
    Stack() {
        head = nullptr;
    }

    bool is_empty() {
        if(head == nullptr) return true;
        return false;
    }

    void push(string value) {
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;

        if(is_empty()) {
            head = new_node;
        } else {
            Node *iter = head;
            while(true) {
                if(iter->next == nullptr) break;
                iter = iter->next;
            }

            iter->next = new_node;
        }
    }

    void print_stack() {
        if(is_empty()) return;
        Node *iter = head;
        while(iter != NULL) {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    string top() {
        if(is_empty()) {
            cout << "Stack is empty" << endl;
            return "";
        } else {
            Node *iter = head;
            while(true) {
                if(iter->next == nullptr) break;
                iter = iter->next;
            }
            
            return iter->data;
        }
    }

    void pop() {
        if(is_empty()) {
            cout << "Stack is empty" << endl;
        } 
        else if(head->next == nullptr) {
            head = nullptr;
        } 
        else {
            Node *iter = head;
            Node *prev;
            while(true) {
                if(iter->next == nullptr) break;
                prev = iter;
                iter = iter->next;
            }
            prev->next = nullptr;
            delete iter;
        }
    }
};

bool is_operator(char ch) {
    set<char> operators = {'+', '-', '/', '*'};
    return !(operators.find(ch) == operators.end());
}

int main() {
    string postfix;
    cout << "Enter postfix: ";
    cin >> postfix;

    Stack st;
    for(int i = 0; i < postfix.size(); i++) {
        if(is_operator(postfix[i])) {
            string second = "";
            string first = "";
            second += st.top(); st.pop();
            first += st.top(); st.pop();
            string new_operand = postfix[i] + first + second;
            st.push(new_operand);
        }
        else {
            string val = "";
            val += postfix[i];
            st.push(val);
        }
    }

    string prefix = st.top();
    cout << "Prefix: " << prefix << endl;

    return 0;
}

// ab*cd/+