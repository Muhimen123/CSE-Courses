#include <bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;
int dp[1000][1000];

int lcs(int i, int j) {
    if(i >= n or j >= m) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    int lc = lcs(i+1, j);
    lc = max(lc, lcs(i, j + 1));
    if(s1[i] == s2[j]) {
        lc = max(lc, 1 + lcs(i+1, j+1));
    }

    return dp[i][j] = lc;
}

void outputTrack(int i, int j) {
    if(i >= n or j >= m) return;
    if(s1[i] == s2[j]) {
        cout << s1[i];
        outputTrack(i+1, j + 1);
        return;
    }

    int x = lcs(i+1, j);
    int y = lcs(i, j+1);

    if(x >= y) outputTrack(i+1, j);
    else outputTrack(i, j+1);
}

int main() {
    memset(dp, -1, sizeof dp);
    string a = "ABRAKADABRA";
    string b = "DABRAKAABRAK";
    s1 = a;
    s2 = b;
    n = s1.size();
    m = s2.size();

    int ans = lcs(0, 0);
    cout << ans << endl;
    outputTrack(0, 0);
    return 0;
}