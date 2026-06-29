#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e4 + 1;
int dpc[maxn], nc[maxn];

int main () {
    int c, i = 0, ans = 0;
    while(cin >> c) {
        nc[i] = c;
        i++;
        dpc[c] = dpc[max(c - 1, 0)] + 1;
    }
    for(int p = 0; p < i; p++) ans = max(ans, dpc[nc[p]]);
    cout << ans;
    return 0;
}
