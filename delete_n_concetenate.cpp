#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int nc[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t, n, c, brneg, brpos, sump;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> c;
        brpos = 0;
        brneg = 0;
        sump = 0;
        for(int x = 0; x < n; x++) {
            cin >> nc[x];
            nc[x] -= c;
            if(nc[x] < 0)brneg++;
            else {
                sump += nc[x];
                brpos++;
            }
        }
        if(brneg <= brpos) cout << sump <<  '\n';
        else {
            sort(nc, nc + n);
            int idx = brneg - ceil(1.0 * (brneg - brpos) / 2);
            while(idx < n && nc[idx] < 0) {
                sump += nc[idx];
                idx++;
            }
            cout << sump << '\n';
        }
    }
    return 0;
}
