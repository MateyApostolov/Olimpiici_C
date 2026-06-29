#include <bits/stdc++.h>
using namespace std;

map <pair<int, pair<int, int>>, bool> mp;

vector <int> d (int num) {
    int k = floor(sqrt(num));
    vector <int> h;
    for(int i = 1; i <= k; i++) {
        if(num % i == 0) {
            if(i * i == num) h.push_back(i);
            else {
                h.push_back(i);
                h.push_back(num / i);
            }
        }
    }
    sort(h.begin(), h.end());
    return h;
}

int main () {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    vector <int> div = d(n);
    mp[{1, {1, n}}] = true;
    for(int i = 0; i < div.size(); i++) {
        int c[3];
        c[0] = 1;
        c[1] = div[i];
        c[2] = n / div[i];
        sort(c, c + 3);
        mp[{c[0], {c[1], c[2]}}] = true;
    }
    for(int i = 0; i < div.size(); i++) {
        vector <int> di = d(n / div[i]);
        for(int x = 0; x < di.size(); x++) {
            int c[3];
            c[0] = div[i];
            c[1] = di[x];
            c[2] = (n / div[i]) / di[x];
            sort(c, c + 3);
            mp[{c[0], {c[1], c[2]}}] = true;
        }
    }
    for(auto x : mp) {
        cout << x.first.first << ' ' << x.first.second.first << ' ' << x.first.second.second << '\n';
    }
    cout << mp.size();
    return 0;
}
