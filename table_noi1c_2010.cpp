#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, k, num, h = 0, sum = 0;
    cin >> n >> m >> k;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> num;
            h++;
            if(h % k == 0) {
                sum += num;
            }
        }
    }
    cout << sum;
    return 0;
}

