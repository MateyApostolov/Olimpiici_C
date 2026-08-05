#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e10 + 1;
int n, a[maxn], b[maxn], dp[maxn];



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        int ans = 0;
        for(int x = 0; x < n; x++) {
            cin >> a[x];
        }
        for(int x = 0; x < n; x++) {
            cin >> b[x];
        }
        int idx = 0;
        cout << slv()
        for(int ep = n - 1; ep >= 0; ep--) {
            for(int idx = 1; i <= n; i++) {
                if(a[idx] == b[idx] && a[idx] == ep) ans += dp[ep + 1];
                if(a[idx] != b[idx] && a[])

            }
            if(a[x] != b[x])
        }
        while(a[idx] != 1 || b[idx] != 1) {

        }
    }

    return 0;
}
