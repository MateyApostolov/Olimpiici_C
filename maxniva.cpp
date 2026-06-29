#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
int dp[maxn][maxn], optl[maxn], optr[maxn];
int pref0[maxn], pref1[maxn];

bool is_ok(int l, int r) {
    if(r <= l) return false;
    if(pref0[r] - pref0[l - 1] == pref1[r] - pref1[l - 1]) return true;
    return false;
}

int main () {
    string s;
    cin >> s;
    if(s[0] == '0') pref0[0]++;
    else pref1[0]++;
    for(int i = 1; i < s.size(); i++) {
        pref0[i] = pref0[i - 1];
        pref1[i] = pref1[i - 1];
        if(s[i] == '0') pref0[i]++;
        else pref1[i]++;
    }
    for(int l = 0; l < s.size(); l++) {
        int r = l - 1;
        while(r + 1 < s.size() && is_ok(l, r)) {
            r++;
            if(s[l] != s[r] && is_ok(l + 1, r - 1)) {
                dp[l][r] = dp[l + 1][r - 1] + 1;
            }
            for(int mid = l + 1; mid < r; mid++) {
                if(!is_ok(l, mid) || !is_ok(mid, r - 1)) continue;
                dp[l][r] = max(dp[l][mid], dp[mid][r - 1]);
                cout << dp[l][r] << ' ';
            }
            optl[l] = max(optl[l], dp[l][r]);
        }
    }
    for(int mid = 1; mid < s.size(); mid++) {
        if(!is_ok(0, mid) || !is_ok(mid, s.size() - 1)) continue;
        dp[0][mid] = max(dp[0][mid], dp[mid][s.size() - 1]);
    }
    cout << dp[0][s.size() - 1];
    return 0;
}

