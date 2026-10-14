#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5;
int nc[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
    }
    vector<vector<int>> trees;
    vector<int> last;
    for(int i = 0; i < n; i++) {
        int l = 0, r = last.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nc[i] < last[mid]) l = mid + 1;
            else r = mid - 1;
        }
        if(l == last.size()) {
            trees.push_back({});
            last.push_back(nc[i]);
        } else {
            last[l] = nc[i];
        }
        trees[l].push_back(i);
    }
    cout << trees.size() << '\n';
    for(int i = 0; i < trees.size(); i++) {
        cout << trees[i].size() << ' ';
        for(int idx = 0; idx < trees[i].size(); idx++) {
            cout << trees[i][idx] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
