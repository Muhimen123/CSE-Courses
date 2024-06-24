#include <bits/stdc++.h>
#include "stack_implementation.h"
using namespace std;

void insert(Stack &st, int tp) {
    if(st.is_empty()) {
        st.push(tp);
    } else {
        int a = st.top();
        st.pop();
        insert(st, tp);
        st.push(a);
    }
}

void reverse(Stack &st) {
    if(!st.is_empty()) {
        int tp = st.top();
        st.pop();
        reverse(st);
        st.push(tp);
        insert(st, tp);
    }
    return;
}

int main() {
    Stack st;
    st.push(520);
    st.push(314);
    st.push(358);
    st.print_stack();
    reverse(st);
    st.print_stack();
    return 0;
}