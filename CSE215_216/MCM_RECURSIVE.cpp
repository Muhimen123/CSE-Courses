#include <bits/stdc++.h>
using namespace std;

vector<int> p;
int dp[3000][3000];

int mcm(int i, int j) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int mn = 1e8;
    for(int k = i; k < j; k++) { 
        int cal = mcm(i, k) + mcm(k+1, j);
        cal += p[i-1] * p[k] * p[j]; 
        mn = min(cal, mn);
    }

    return dp[i][j] = mn;
}

int main() {
    memset(dp, -1, sizeof(dp));
    p = {30, 35, 15, 5, 10, 20, 25};
    int n = p.size();
    cout << mcm(1, n-1) << endl; 
    return 0;
}
