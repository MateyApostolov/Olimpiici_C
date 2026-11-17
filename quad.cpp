#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, k, h = 0, x, y, kv1 = 0, kv2 = 0, kv3 = 0, kv4 = 0;
    cin >> n >> m >> k;
    int d2[n + 1][m + 1];
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> d2[r][c];
            h++;
            if(h == k) {
                x = r;
                y = c;
            }
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            if(r < x && c > y) {
                kv1 += d2[r][c];
            }
            if(r < x && c < y) {
                kv2 += d2[r][c];
            }
            if(r > x && c < y) {
                kv3 += d2[r][c];
            }
            if(r > x && c > y) {
                kv4 += d2[r][c];
            }
        }
    }
    cout << kv1 << ' ' << kv2 << ' ' << kv3 << ' ' << kv4;
    return 0;
}
