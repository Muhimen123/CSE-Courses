#include <bits/stdc++.h>
using namespace std;

int main() {
    /* CONSIDERING THE STRING TO BE 1 INDEXED */
    string a = "ABRAKADABRA";
    string b = "DABRAKAABRAK";

    int dp[a.size() + 1][b.size() + 1];
    memset(dp, 0, sizeof dp);
    
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] =  1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;

    string s = "";
    pair<int, int> bck = {a.size(), b.size()};
    while(bck.first >= 0 and bck.second >= 0) {
        int i = bck.first;
        int j = bck.second;

        if(dp[i-1][j-1] + 1 == dp[i][j]) {
            i--;
            j--;
            s += a[i];
        } else if(dp[i-1][j] == dp[i][j]) {
            i--;

        } else {
            j--;
        }
        bck = {i, j};

    }

    reverse(s.begin(), s.end());
    cout << s << endl;
    
    return 0;
}