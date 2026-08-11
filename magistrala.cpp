#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 1;
bool c[4][maxn][maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, x, y, cz, ct, cp, dir, p, ans = 0;
    cin >> n >> k >> x >> y >> cz >> ct >> cp;
    for(int i = 1; i <= k; i++) {
        cin >> dir >> p;
        if(dir == 0) {
            if(x - p <= 0) {
                cout << "INVALID ROUTE\n" << i;
                return 0;
            }
            for(int idx = 1; idx <= p; idx++) {
                c[0][x][y] = true;
                x--;
                c[2][x][y] = true;
            }
        }
        if(dir == 1) {
            if(y + p > n) {
                cout << "INVALID ROUTE\n" << i;
                return 0;
            }
            for(int idx = 1; idx <= p; idx++) {
                c[1][x][y] = true;
                y++;
                c[3][x][y] = true;
            }
        }
        if(dir == 2) {
            if(x + p > n) {
                cout << "INVALID ROUTE\n" << i;
                return 0;
            }
            for(int idx = 1; idx <= p; idx++) {
                c[2][x][y] = true;
                x++;
                c[0][x][y] = true;
            }
        }
        if(dir == 3) {
            if(y - p <= 0) {
                cout << "INVALID ROUTE\n" << i;
                return 0;
            }
            for(int idx = 1; idx <= p; idx++) {
                c[3][x][y] = true;
                y--;
                c[1][x][y] = true;
            }
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int col = 1; col <= n; col++) {
             int h = 0;
             for(int i = 0; i < 4; i++) {
                if(c[i][r][col]) h++;
             }
            if(h == 1 || h == 2) ans += cz;
            if(h == 3) ans += ct;
            if(h == 4) ans += cp;
        }
    }
    cout << "VALID ROUTE\n" << ans;
    return 0;
}
