#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const int maxb = 31;
long long n, k, nc[maxn], br[maxb], r, ans;

bool ch() {
    int a = 0;
    for(int i = 0; i < maxb; i++) {
        if(br[i] > 0) a += (1 << i);
    }
    return (a < k);
}

int main () {
    cin >> n >> k;
    long long nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int l = 0; l < n; l++) {
        while(r < n && ch()) {
            for(int x = 0; x < maxb; x++) {
                br[x] += ((nc[r] >> x) & 1);
            }
            r++;
        }
        if(!ch()) ans += n - r + 1;
        for(int x = 0; x < maxb; x++) {
            br[x] -= ((nc[l] >> x) & 1);
        }
    }



    cout << ans;
    return 0;
}

