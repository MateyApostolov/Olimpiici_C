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
        char beg = s[0], fin = s[s.size() - 1];
        for(int x = 0; x < s.size(); x++) {
            cnt[s[x]]++;
        }
        bool t = true;
        char pr = s[0], h;
        int curl = 0, maxl = 0, ans = 0;
        for(int x = 1; x < s.size() - 1; x++) {
            cout << s[x];
            if(pr == s[x]) curl++;
            else if(t && x + 1 < s.size() && pr == s[x + 1]) {
                t = false;
                curl++;
                x++;
            }
            else {
                if(maxl < curl) {
                    h = s[x];
                    maxl = curl;
                }
                curl = 1;
                t = true;
            }
            ans++;
        }
        cout << ans - maxl + 1;
        cout << '\n';
    }

    return 0;
}
