#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7e2 + 2;
char d2[MAXN][MAXN];
int Rt[MAXN][MAXN], Dn[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int r = 1; r <= n; r++)
    for(int c = 1; c <= m; c++) cin >> d2[r][c];
    for(int r = n; r >= 1; r--) {
        for(int c = m; c >= 1; c--) {
            if(d2[r][c] == '-' || d2[r][c] == '0') Rt[r][c] = Rt[r][c+1] + 1;
            if(d2[r][c] == '|' || d2[r][c] == '0') Dn[r][c] = Dn[r+1][c] + 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(d2[i][j] != '1' && d2[i][j] != '0') continue;
            int hi = min(Rt[i][j+1], Dn[i+1][j]) + 1;
            hi = min(hi, min(n - i, m - j));
            for(int L = hi; L >= 1; L--) {
                char topr = d2[i][j+L], botl = d2[i+L][j], botr = d2[i+L][j+L];
                if((topr == '2' || topr == '0') && (botl == '4' || botl == '0') && (botr == '3' || botr == '0') &&
                    Rt[i+L][j+1] >= L - 1 && Dn[i+1][j+L] >= L - 1) {
                    bool not0 = false;
                    for(int k = 0; k <= L; k++) {
                        if(d2[i][j+k] != '0' || d2[i+k][j] != '0') not0 = true;
                    }
                    if(not0) cout << i << ' ' << j << ' ' << L << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
