#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;
const int maxs = 1e5;

long long dp[maxn][maxs][2], nc[maxn];

int main () {
    long long n, s, k, ansp, sum;
    cin >> n >> s >> k;
    ansp = k + s * (s + 1) / 2;
    for(int i = 1; i <= n; i++) cin >> nc[i];

    /*bool t1 = true, t2 = true;
    for(int i = 1; i < s; i++) {
        if(nc[i] > nc[i + 1]) {
            t1 = false;
            break;
        }
    }
    for(int i = s; i < n; i++) {
        if(nc[i] > nc[i + 1]) {
            t2 = false;
            break;
        }
    }
    if(t1 && t2) {
        int i = s, j = s + 1;
        while(k >= 0) {
            if(nc[i] < nc[j] && j - i <= k) {
                swap(nc[i], nc[j]);
                j++;
                i--;
                k = k - j + i;
            } else {
                break;
            }
        }
        for(int i = 1; i <= s; i++) {
            sum += nc[i];
        }
        cout << sum;
        return 0;
    }*/


    for(int i = 1; i <= s; i++) {
        for(int x = 0; x <= ansp; x++) {
            dp[i][x][0] = INT_MIN;
        }
    }
    for(int pos = 1; pos <= n; pos++) {
        for(int i = 0; i <= s; i++) {
            for(int ts = 0; ts <= ansp; ts++) {
                dp[i][ts][pos % 2] = dp[i][ts][1 - pos % 2];
                if(i > 0 && ts >= pos) dp[i][ts][pos % 2] = max(dp[i][ts][pos % 2], nc[pos] + dp[i - 1][ts - pos][1 - pos % 2]);
            }
        }
    }
    cout << dp[s][ansp][n % 2];
    return 0;
}
