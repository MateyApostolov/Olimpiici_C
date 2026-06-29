#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

struct segt{
    int n;
    vector <int> dtn;
    segt(int n) : n(n) {
        dtn.resize(4 * n + 5);
    }
    void upd(int node, int l, int r, int x, int v) {
        if(l == r) dtn[node] = max(dtn[node], v);
        else {
            int mid = (l + r) / 2;
            if(l <= x && x <= mid) upd(2 * node + 0, l, mid, x, v);
            else upd(2 * node + 1, mid + 1, r, x, v);
            dtn[node] = max(dtn[2 * node], dtn[2 * node + 1]);
        }
    }
    int qry(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        else if(ql <= l && r <= qr) return dtn[node];
        else {
            int mid = (l + r) / 2;
            return max(qry(2 * node + 0, l, mid, ql, qr), qry(2 * node + 1, mid + 1, r, ql, qr));
        }
    }
    void upd(int x, int v) {
        upd(1, 1, n, x, v);
    }
    int qry(int l, int r) {
        return (l <= r ? qry(1, 1, n, l, r): 0);
    }
};

int n, nc[maxn];

int main () {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    {
        vector <int> comp(nc, nc + n);
        sort(comp.begin(), comp.end());
        comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
        for(int i = 0; i < n; i++) {
            nc[i] = lower_bound(comp.begin(), comp.end(), nc[i]) - comp.begin() + 1;
        }
    }
    segt segmtree(n);
    for(int i = 0; i < n; i++) {
        int x = segmtree.qry(1, nc[i] - 1) + 1;
        segmtree.upd(nc[i], x);
    }

    cout << segmtree.qry(1, n) << '\n';
    return 0;
}
