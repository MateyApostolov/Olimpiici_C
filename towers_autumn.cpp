#include <bits/stdc++.h>
using namespace std;

const int maxs = 5001;
const int d7 = 1e9 + 7;
int s, mm[maxs][maxs][2];

int t (int hs, int x, int p) {
    if(hs == 0) return 1;
    if(p == 0 && x >= hs) return 0;
    if(p == 1 && x <= 1) return 0;
    if(mm[hs][x][p] != 0) return mm[hs][x][p];
    if(p == 0) return mm[hs][x][p] = (t(hs - (x + 1), x + 1, 1) + t(hs, x + 1, 0)) % d7;
    else return mm[hs][x][p] = (t(hs - (x - 1), x - 1, 0) + t(hs, x - 1, 1)) % d7;
}

int main () {
    cin >> s;
    cout << (t(s, 0, 0) + t(s, s, 1)) % d7;
    return 0;
}
