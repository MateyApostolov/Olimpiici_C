#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct elm{
    int cnta = 0;
    int cntb = 0;
    int minv = INF;
};

struct ST{
    int n;
    vector<elm> tree;
    elm null;
    ST(vector<bool> const& arr, int N) {
        n = N;
        tree.resize(4 * n + 4, null);
    }
    elm merg(elm a, elm b) {
        elm c;
        c.cnta = a.cnta + b.cnta;
        c.cntb = a.cntb + b.cntb;
        c.minv = min(min(a.minv, b.minv), abs(c.cnta - c.cntb));
    }
    void build(vector<bool> const& arr, int node, int l, int r) {
        if(l == r) {
            if(arr[l]) {
                tree[node] = {1, 0, 1};
            } else {
                tree[node] = {0, 1, -1};
            }
        }
        int mid = (l + r) / 2;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);
        tree[node] = merg(tree[2 * node], tree[2 * node + 1]);
    }
    void update(vector<bool> const& arr, int node, int l, int r, int idx, bool x) {
        if(l == r) {
            if(arr[l]) {
                if(!x) tree[node] = merg(tree[node], {-1, 1, INF});
            } else {
                if(x) tree[node] = merg(tree[node], {1, -1, INF});
            }
        }
        if(idx > r && idx < l) return;
        int mid = (l + r) / 2;
        if(idx <= mid) update(arr, 2 * node, l, mid, idx, x);
        else update(arr, 2 * node + 1, mid + 1, r, idx, x);
        tree[node] = merg(tree[2 * node], tree[2 * node + 1]);
    }
    elm query(int node, int l, int r, int ql, int qr) {
        if(l > qr && r < ql) return null;
        if(l >= ql && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return merg(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }
    void build(vector<bool> const& arr) {
        build(arr, 1, 1, n);
    }
    void update(vector<bool> const& arr, int idx, bool x) {
        update(arr, 1, 1, n, idx, x);
    }
    elm query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, t, l, r;
    cin >> n;
    vector<bool> nc(n);
    char c;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        if(c == 'A') nc[i] = 1;
        else nc[i] = 0;
    }
    ST st(nc, n);
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> t;
        if(t == 1) {
            cin >> i >> c;
            if(c == 'A') st.update(nc, i, 1);
            else st.update(nc, i, 0);

        } else {
            cin >> l >> r;
            elm res = st.query(l, r);
            if(res.minv < 0) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}
