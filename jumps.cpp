#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, nc;
    cin >> n;
    vector <int> dp(601);
    for(int i = 0; i < 601; i++) dp[i] = 3e6;
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        if(dp[0] == 3e6) continue;
        for(int x = 1; x <= nc; x++) dp[x] = min(dp[x], dp[0] + 1);
        dp.erase(dp.begin());
        dp.push_back(3e6);

    }
    if(dp[n - 1] == 3e6) dp[n - 1] = -1;
    cout << dp[n - 1];
    return 0;
}
