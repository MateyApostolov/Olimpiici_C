#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int tbl[maxn][maxn], htbl[maxn][maxn];


int main () {
    int Q, q, f, n, m, h = 1;
    cin >> Q >> q >> f >> n >> m;
    tbl[1][1] = Q * 1000;
    if(f > maxn) {
        cout << 0;
        return 0;
    }
    while(h <= f) {
        bool t = false;
        if(h == f) {
            cout << min(tbl[n][m], q);
            return 0;
        }
        for(int r = 1; r <= h; r++) {
            for(int c = 1; c <= h; c++) {
                int prel = (tbl[r][c] - q) / 4;
                if(tbl[r][c] <= q || prel == 0) continue;
                t = true;


                htbl[r][c] += prel;
                htbl[r + 1][c] += prel;
                htbl[r][c + 1] += prel;
                htbl[r + 1][c + 1] += prel;
            }
        }
        if(!t) {
            cout << 0;
            return 0;
        }
        for(int r = 1; r <= h + 1; r++) {
            for(int c = 1; c <= h + 1; c++) {
                tbl[r][c] = htbl[r][c];
                htbl[r][c] = 0;
            }
        }
        h++;
    }
    cout << 0;
    return 0;
}
