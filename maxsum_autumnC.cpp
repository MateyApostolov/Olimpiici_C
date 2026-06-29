#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const int maxk = 1e3;
const int inf = 1e9;
int nc[maxn], kc[maxk], dpl[maxn], dpr[maxn];

int n, k, ans = - inf;

int main () {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        dpl[i] = - inf;
        dpr[i] = - inf;
    }
    for(int i = 0; i < k; i++) {
        cin >> kc[i];
    }
    sort(kc, kc + k);
    dpl[0] = nc[0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(i + kc[j] >= n) break;
            dpl[i + kc[j]] = max(dpl[i + kc[j]], dpl[i] + nc[i + kc[j]]);
        }
    }
    dpr[n - 1] = nc[n - 1];
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < k; j++) {
            if(i - kc[j] < 0) break;
            dpr[i - kc[j]] = max(dpr[i - kc[j]], dpr[i] + nc[i - kc[j]]);
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        dpr[i] = max(dpr[i], dpr[i + 1]);
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, dpl[i] + dpr[i]);
    }
    cout << ans;
    return 0;
}
