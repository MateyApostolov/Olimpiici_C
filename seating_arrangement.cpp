#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, x, s;
        cin >> n >> x >> s;
        int free_seats = 0, tables_left = x, AE = 0, ans = 0;
        char c;
        for(int idx = 1; idx <= n; idx++) {
            cin >> c;
            if(c == 'I') {
                if(tables_left == 0) continue;
                tables_left--;
                free_seats += s - 1;
                ans++;
            }
            if(c == 'E') {
                if(free_seats == 0) {
                    if(AE == 0) continue;
                    if(tables_left == 0) continue;
                    AE--;
                    tables_left--;
                    free_seats += s - 1;
                    ans++;
                } else {
                    free_seats--;
                    ans++;
                }
            }
            if(c == 'A') {
                if(free_seats == 0) {
                    if(tables_left == 0) continue;
                    tables_left--;
                    free_seats += s - 1;
                    ans++;
                } else {
                    free_seats--;
                    ans++;
                    AE++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
