#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 1;
int nums[maxn];
set<int> cidx;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, ans = 0;
    cin >> n >> q;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            ans ^= cidx[x];
            cidx[x]++;
            ans ^= cidx[x];
            cout << ans << '\n';
            continue;
        }
        for(auto cidx.begin(); cidx.end();) {
            int it = *it;
            ans ^= cidx[idx];
            cidx[idx]--;
            ans ^= cidx[idx];
            if(cidx[idx] == 0){
                it = cidx.erase(it);
            } else {
                it++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
