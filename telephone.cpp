#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 1;
int nc[maxn];

int main () {
    int n;
    long long res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    vector <int> inter;
    for(int i = 0; i < n; i++) {
        int l = 0, r = inter.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nc[inter[mid]] > nc[i]) l = mid + 1;
            else r = mid - 1;
        }
        if(r == -1) res += i;
        else res += i - inter[r] + r;
        while(!inter.empty() && nc[inter.back()] < nc[i]) inter.pop_back();
        inter.push_back(i);
    }
    cout << res;
    return 0;
}
