#include <bits/stdc++.h>
using namespace std;

const int maxn = 250000;
const int d2 = 63;
bool h[maxn][d2], s1, s0;
int st1[d2], st0[d2], n, k, m = -1, r = -1;
long long mask[d2], ans, nc;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    mask[0] = 1;
    for(int i = 1; i < 63; i++) mask[i] = 2 * mask[i - 1];
    for(int i = 0; i < n; i++) {
        cin >> nc;
        for(int x = 0; x < k; x++) h[i][x] = nc & mask[x];
    }

    for(int l = 0; l < n - 1; l++) {
        while(m + 1 < n && !s1) {
            m++;
            s1 = true;
            for(int i = 0; i < k; i++) {
                st1[i] += h[m][i];
                if(st1[i] == 0) s1 = false;
            }
            if(r >= m) {
                for(int i = 0; i < k; i++) {
                    st0[i] -= !h[m][i];
                }
            }
        }
        if(!s1) break;
        if(r < m) r = m;
        s0 = true;
        for(int i = 0; i < k; i++) {
            if(st0[i] == 0) s0 = false;
        }
        while(r < n && !s0) {
            r++;
            s0 = true;
            for(int i = 0; i < k; i++) {
                if(!h[r][i]) st0[i]++;
                else if(st0[i] == 0) s0 = false;
            }
        }
        if(!s0) break;
        ans += n - r;
        s1 = true;
        for(int i = 0; i < k; i++) {
            st1[i] -= h[l][i];
            if(st1[i] == 0) s1 = false;
        }
    }
    cout << ans;
    return 0;
}
