#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxc = 71;
const int prime = 20;
int dp[maxc][prime], msk[maxc];
map <int, int> k;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int main () {
    int n, c, prv = 0;
    cin >> n;
    for(int i = 0; i < maxc; i++) msk[i] = -1;
    for(int i = 0; i < n; i++) {
        cin >> c;
        k[c]++;
        int h = 0;
        if(msk[c] != -1) continue;
        msk[c] = 0;
        while(c > 1) {
            while(c % primes[h] == 0) {
                c /= primes[h];
                msk[c] ^= (1 << h);
            }
            h++;
        }
    }
    dp[0][0] = 1;
    for(int x = 1; x < maxc; x++) {
        int cnt = k[x];
        int v1 = dp[prv][msk[x]] * (cnt / 2);
        if(cnt % 2 != 1) v1 += dp[prv][msk[x]];

        int newmask = msk[x] ^ x;
        int v2 =  dp[prv][newmask] * (cnt / 2);
        if(cnt % 2 != 1) v2 += dp[prv][newmask];

        if(v1 < v2) {
            msk[x] = newmask;
            dp[x][msk[x]] = v2;
        } else {
            dp[x][msk[x]] = v1;
        }
        prv = x;
    }
    cout << dp[70][0];
    return 0;
}
