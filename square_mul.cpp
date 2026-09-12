#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxc = 71;
const int prime = 20;
int dp[maxc][prime], msk[maxc];
map <int, int> k;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
vector<int> nums;

int main () {
    int n, c, prv = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < maxc; i++) msk[i] = -1;
    for(int i = 0; i < n; i++) {
        cin >> c;
        if(!k[c]) nums.push_back(c);
        k[c]++;
        if(msk[c] != -1) continue;
        int h = 0, hc = c;
        msk[c] = 0;
        while(hc > 1) {
            while(hc % primes[h] == 0) {
                hc /= primes[h];
                msk[c] ^= (1 << h);
            }
            h++;
        }
    }
    sort(nums.begin(), nums.end());
    dp[1][0] = (1 << k[1]) - 1;
    for(int x = 2; x < nums.size(); x++) {
        int cnt = k[x];
        ///    dp[x][msk[x]] = dp[x - 1][msk[x - 1]];
        int mul = 1;
        for(int i = 2; i < cnt; i += 2) {

        }
        int v1 = dp[x - 1][msk[x]] * (cnt / 2);
        if(cnt % 2 != 0) v1 += dp[x - 1][msk[x]];

        int newmask = msk[x] ^ msk[x - 1];
        int v2 =  dp[x - 1][newmask] * (cnt / 2);
        if(cnt % 2 != 0) v2 += dp[x - 1][newmask];

        if(v1 < v2) {
            msk[x] = newmask;
            dp[x][msk[x]] = v2;
        } else {
            dp[x][msk[x]] = v1;
        }
    }
    for(int i = 1; i < maxc; i++) {
        cout << dp[i][0] << ' ';
        ans = max(ans, dp[i][0]);
    }
    cout << '\n' << ans;
    return 0;
}
