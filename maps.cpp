#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
const int d7 = 1e9 + 7;
long long dp[maxn];

int main () {
    int n, m, num;
    cin >> n >> m;
    vector<int> nc;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> num;
            nc.push_back(num);
        }
    }
    sort(nc.begin(), nc.end());
    dp[0] = 1;
    dp[1] = 1;
    ///for(int i = 0; i < nc.size(); i++) cout << nc[i] << ' ';
    ///cout << '\n';
    for(int i = 2; i < nc.size(); i++) {
        int v1 = 0, p1, v2 = 0, p2, j = i;
        while(j - 1 >= 0 && (v1 == 0 || v2 == 0)) {
            j--;
            if(nc[j] == nc[i]) continue;
            if(v1 < nc[j]) {
                v1 = nc[j];
                p1 = j;
                continue;
            }
            if(v2 < nc[j]) {
                v2 = nc[j];
                p2 = j;
                continue;
            }
        }
        dp[i] = (dp[p1] + dp[p2]) % d7;
    }
    cout << dp[nc.size() - 1];
    return 0;
}
