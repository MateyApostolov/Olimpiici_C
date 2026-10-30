#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, f, need;
    cin >> n >> k;
    vector<int> c(n - k + 1), first(k, 0);
    for(auto &x : c) cin >> x;
    for(int i = 0; i < c.size() - 1; i++) {
        if(first[i % k] == 0) first[i % k] = c[i + 1] - c[i];
    }
    f = count(first.begin(), first.end(), 0);
    need = c[0] - count(first.begin(), first.end(), -1);
    for(int p = 2; p <= f; p++) {
        bool prime = true;
        for(int d = 2; d * d <= p; d++) {
            if(p % d == 0) {
                prime = false;
                break;
            }
        }
        if(!prime) continue;
        int cnt = 0;
        for(long long q = p; q <= f; q *= p) {
            cnt += f / q - need / q - (f - need) / q;
        }
        if(cnt > 0) cout << p << ' ' << cnt << '\n';
    }
    return 0;
}
