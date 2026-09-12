#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    string s1, s2;
    for(int i = 0; i < t; i++) {
        cin >> n;
        long long nc[n], ans[n];
        map<long long, vector<int>> pos;
        for(int x = 0; x < n; x++) {
            cin >> nc[i];
            pos[nc[i]].push_back(i);
        }
        for(auto [k, x] : pos) {
           for(int idx = 0; idx < x.size(); idx++) cout << x[idx] << ' ';
           cout << '\n' << '\n';
        }
        sort(nc, nc + n);
        long long h = 0, pr, br = 0, num;
        int beg = 0;
        while(beg + 1 < n && nc[beg] == nc[beg + 1]) beg++;
        pr = nc[beg];
        for(int idx = beg + 1; idx < n; idx++) {
            if(nc[idx] == pr) {
                h += nc[idx];
                br++;
            } else {
                num = h / br;
                for(int x = 0; x < br; x++) {
                    ans[pos[num][x]] = num;
                }
            }
        }
        num++;
        for(int x = 0; x < br; x++) {
            ans[pos[num][x]] = num;
        }
        for(int idx = 0; idx < n; idx++) {
            cout << ans[idx] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

