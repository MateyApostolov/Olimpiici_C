#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, a, b, num, ans = 0;
    cin >> n >> a >> b;
    bool dp[b + 1] = {};
    dp[0] = true;
    for(int i = 0; i < n; i++) {
        cin >> num;
        for(int x = b; x >= 0; x--) {
            if(dp[x] && x + num <= b) dp[x + num] = true;
        }
    }
    for(int i = a; i <= b; i++) ans += dp[i];
    cout << ans;
    return 0;
}
