#include <bits/stdc++.h>
using namespace std;

struct segt{
    int n;
    vector <int> dtn;
    segt(int n) : n(n) {
        dtn.resize(4 * n + 5);
    }
    void upd(int node, int l, int r, int x, int v) {
        if(l == r) dtn[node]++;
        else {
            int mid = (l + r) / 2;
            if(l <= x && x <= mid) upd(2 * node + 0, l, mid, x, v);
            else upd(2 * node + 1, mid + 1, r, x, v);
            dtn[node] = dtn[2 * node] + dtn[2 * node + 1];
        }
    }
    int qry(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        else if(ql <= l && r <= qr) return dtn[node];
        else {
            int mid = (l + r) / 2;
            return qry(2 * node + 0, l, mid, ql, qr) +  qry(2 * node + 1, mid + 1, r, ql, qr);
        }
    }
    void upd(int x, int v) {
        upd(1, 1, n, x, v);
    }
    int qry(int l, int r) {
        return qry(1, 1, n, l, r);
    }
};
