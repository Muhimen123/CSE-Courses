#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<int> country;
int n, e;
int total_color;
int colored = 0;

bool isSafe(int node) {
    for(auto child: adj[node]) {
        if(country[child] == country[node]) return false;
    }

    return true;
}

bool color(int node) {
    if(node == n) return true;

    for(int c = 1; c <= total_color; c++) {
        country[node] = c;
        if(isSafe(node)) {
            if(color(node + 1)) return true;
        }
        country[node] = 0;
    }

    return false;
}


int main() {

    adj = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3, 4},
        {1, 2, 4},
        {2, 3}
    };


    n = adj.size();
    country = vector<int>(n, 0);
    total_color = 1;

    bool ans = color(0);
    if(ans) {
        cout << "Coloring is possible\n";
        for(int i = 0; i < n; i++) {
            cout << "Country: " << i << " Color: " << country[i] << endl;
        }
    } else {
        cout << "Coloring is not possible\n";
    }
    
    return 0;
}