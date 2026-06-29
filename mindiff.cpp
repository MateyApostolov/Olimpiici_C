#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 1e5 + 1;
int num[maxn], pref[maxn];

int main () {
    int n, q, nc;
    cin >> n >> q;
    set <int> s;
    for(int i = 0; i <= n; i++) pref[i] = INF;
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 1; i <= n; i++) {
        auto [it, isrep] = s.insert(num[i]);
        if(!isrep) {
            pref[i] = 0;
            continue;
        }
        pref[i] = pref[i - 1];
        if(it != s.begin()) {
            auto prit = prev(it);
            pref[i] = min(pref[i], *it - *prit);
        }
        if(next(it) != s.end()) {
            auto nxit = next(it);
            pref[i] = min(pref[i], *nxit - *it);
        }
    }
    for(int i = 0; i < q; i++) {
        int qh;
        cin >> qh;
        cout << pref[qh] << ' ';
    }

    return 0;
}
