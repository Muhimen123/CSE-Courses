#include <bits/stdc++.h>
using namespace std;

const int N = 300;
const int MAX = 1e8;


int dp[N][N];
int split[N][N];

void printAnswer(int i, int j, char& name) {
    if(i == j) {
        cout << name++;
        return;
    }

    cout << "(";
    printAnswer(i, split[i][j], name);
    printAnswer(split[i][j]+1, j, name);
    cout << ")";
}

int main() {
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    int n = p.size();
    
    memset(dp, MAX, sizeof(dp));
    for(int i = 0; i < N; i++) dp[i][i] = 0;

    for(int l = 2; l <= n; l++) {
        for(int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = MAX;

            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if(dp[i][j] > cost) {
                    dp[i][j] = cost; 
                    split[i][j] = k;
                }
            }
        }
    } 

    cout << "Minimum cost: " << dp[1][n-1] << endl;
    char name = 'A';

    cout << "Optimal Parentization: ";
    printAnswer(1, n-1, name);
}