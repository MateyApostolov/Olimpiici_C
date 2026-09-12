#include <bits/stdc++.h>
using namespace std;

int main () {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int t, n;
    cin >> t;
    string s1, s2;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cin >> s1 >> s2;
        vector<int> posb;
        for(int x = 0; x < n; x++) {
            if(s2[x] == 1) posb.push_back(x);
        }
        vector<pair<int, int>> ons;
        for(int x = 0; x < n; x++) {
            if(s1[x] == '1') ons.push_back({x, 0});
        }
        int h = -1;
        for(int x = 0; x < n; x++) {
            if(posb[h] == x) {
                h++;
            } else {
                ons[h].second++;
            }
        }
        bool t = false;
        for(int x = 0; x < ons.size(); x++) {
            if(ons[x].second % 2 == 0) {
                cout << "NO\n";
                break;
                t = true;
            }
        }
        /*for(int x = ons.size() - 1; x >= 0; x--) {
            cout << ons[x].first << ':' << ons[x].second << '\n';
        }
        bool t = false;
        for(int x = ons.size() - 1; x >= 0; x--) {

            if(ons[x].second % 2 == 0) {
                if(x - 1 >= 0) ons[x - 1].second += ons[x].second;
            } else {
                if(x - 1 >= 0 && ons[x - 1].first + 1 != ons[x].first) {
                    cout << "NO\n";
                    t = true;
                    break;
                }
            }
        }*/
        if(t) continue;
        cout << "YES\n";
    }

    return 0;
}
