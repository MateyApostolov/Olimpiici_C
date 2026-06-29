#include <bits/stdc++.h>
using namespace std;

const int maxn = 2002;
int dp[maxn][maxn], ans;


int main () {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i1 = 1; i1 <= s1.size(); i1++) {
        for(int i2 = 1; i2 <= s2.size(); i2++) {
            if(s1[i1 - 1] == s2[i2 - 1]) {
                dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                ans = max(ans, dp[i1][i2]);
            }
        }
    }
    cout << ans;
    return 0;
}
