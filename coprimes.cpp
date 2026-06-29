#include <bits/stdc++.h>
using namespace std;

const int maxc = 1e3 + 1;
const int maxn = 1e5 + 1;
int nmp[maxc];
bool pr[maxc];
vector <int> razl[maxn];

void eratosten () {
    for(int d = 2; d < maxc; d++) {
        if(nmp[d] != 0) continue;
        nmp[d] = d;
        for(int h = d * d; h < maxc; h += d) {
            if(nmp[h] != 0) continue;
            nmp[h] = d;
        }
    }
}

void raz(int num, int i) {
    while(num > 1) {
        razl[i].push_back(nmp[num]);
        num /= nmp[num];
    }
}

int main () {
    eratosten();
    int n, nc, r = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        raz(nc, i);
    }
    for(int l = 0; l < n - 1; l++) {
        for(auto x : razl[l]) pr[x] = true;
        if(l > r) r = l;
        while(r + 1 < n) {
            bool t = true;
            for(auto x : razl[r + 1]) {
                if(pr[x]) t = false;
            }
            if(!t) break;
            r++;
            for(auto x : razl[r]) pr[x] = true;
            ans = max(ans, r - l + 1);
        }

        for(auto x : razl[l]) pr[x] = false;
    }
    cout << ans;
    return 0;
}
