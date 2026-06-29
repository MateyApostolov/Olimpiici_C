#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
long long mm[maxn][maxn];
int n, p, s;

long long sumc (int brl, int suml) {
    if(suml < 0 || brl < 0) return 0;
    if(suml == 0 && brl == 0) return 1;
    if(mm[brl][suml] != 0) return mm[brl][suml];
    long long v = 0;
    for(int i = 0; i < p; i++) {
        if(brl == n && i == 0) continue;
        v += sumc(brl - 1, suml - i);
    }
    return mm[brl][suml] = v;
}

int main () {
    cin >> n >> p >> s;
    cout << sumc(n, s);
    return 0;
}
