#include <bits/stdc++.h>
using namespace std;

const int d7 = 1e9 + 7;
const int maxn = 2 * 1e4 + 1;
int n, k;
unordered_map <pair<int,int>, int> mm;

int brs(int n, int prc) {
    if(mm[{n, prc}] != 0) return mm[{n, prc}];
    if(prc > k) return 0;
    if(n == 0) return 1;
    if(prc == k) return brs(n - 1, 0);
    return mm[{n, prc}] = (brs(n - 1, 0) + brs(n - 1, prc + 1)) % d7;
}

int main () {
    cin >> n >> k;
    k--;
    cout << brs(n - 1, 0);
    return 0;
}
