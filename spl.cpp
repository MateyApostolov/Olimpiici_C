#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, c, ans = 0;
    cin >> n;
    vector <long long> nc;
    for(int i = 0; i < n; i++) {
        cin >> c;
        nc.push_back(c);
    }
    for(int i = 1; i < n; i++) {
        nc[i] += nc[i - 1];
    }
    set <long long> m;
    m.insert(0);
    for(auto x : nc) {
        if(m.find(x) != m.end()) {
            ans++;
            m.clear();
        }
        m.insert(x);
    }
    cout << ans;
    return 0;
}
