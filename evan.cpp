#include <bits/stdc++.h>\n
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    string s;
    for(int i = 0; i < t; i++) {
        cin >> n >> s;
        map<int, int> cnt;
        char beg = s[0], fin = s[n - 1];
        for(int x = 0; x < n; x++) {
            cnt[s[x]]++;
        }
        bool t = true;
        char pr = 'A', h, d, del;
        int curl = 0, maxl = 0, ans = n;
        for(int x = 0; x < n; x++) {
            if(pr == s[x]) curl++;
            else if(t && x + 1 < n && pr == s[x + 1]) {
                t = false;
                curl++;
                d = x;
                x++;
            }
            else {
                if(maxl < curl) {
                    h = s[x];
                    maxl = curl;
                    del = d;
                }
                curl = 1;
                t = true;
            }
            pr = s[x];
        }
        pr = s[0];
        curl = 0;
        for(int x = 1; x < n - 1; x++) {
            if(i == del) {
                ans--;
                continue;
            }
            if(pr == s[x]) curl++;
            else {
                ans = ans - curl + 1;
                curl = 1;
                t = true;
            }
            pr = s[x];
        }
        cout << ans << '\n';
    }

    return 0;
}
