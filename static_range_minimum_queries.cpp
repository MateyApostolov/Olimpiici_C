#include <bits/stdc++.h>
using namespace std;


const int maxl2 = 18;
const int maxn = 2e5 + 1;
int n, q, sp[maxl2][maxn], l2[maxl2 + 1];


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> sp[0][i];
    }
    l2[1] = 0;
    for(int i = 2; i <= maxl2; i++) l2[i] = l2[i / 2] + 1;
    for(int l = 1; l < maxl2; l++) {
        for(int i = 0; i + (i << l) - 1 < n; i++) {
            sp[l][i] = min(sp[l - 1][i], sp[l - 1][i + (1 << (l - 1))]);
        }
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int j = l2[r - l + 1];
        cout << min(sp[j][l], sp[j][r - (1 << j) + 1]) << '\n';
    }
    return 0;
}

