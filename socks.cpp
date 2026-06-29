#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k;
    cin >> t;
    for(int x = 0; x < t; x++) {
        cin >> n >> k;
        int nc[2 * n], l = 0;
        bool t = true;
        for(int i = 0; i < 2 * n; i++) cin >> nc[i];
        sort(nc, nc + 2 * n);
        for(int i = 0; i < 2 * n - 1; i++) {
            if(nc[i + 1] - nc[i] > k) {
                if((i - l + 1) % 2 != 0) {
                    t = false;
                    break;
                }
                if(nc[i] - nc[l] > k) {
                    t = false;
                    break;
                }
                l = i + 1;
            }
        }
        if(t && (2 * n - l) % 2 == 0 && nc[2 * n - 1] - nc[l] <= k) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
