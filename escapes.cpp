#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, c, l, r, s1 = 0, s2 = 0, ns1 = 0, ns2 = 0, pr = 0, ew1 = 0, ew2 = 0, ns0, ew0;
    cin >> n;
    vector <pair<int, int>> sns;
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> l >> r;
        sns.push_back({l - 1, 1});
        sns.push_back({r, 2});
    }
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> l >> r;
        sns.push_back({l - 1, 3});
        sns.push_back({r, 4});
    }
    sort(sns.begin(), sns.end());
    for(int i = 0; i < sns.size(); i++) {
        if(s1 > 0 && s2 > 0) ns2 += sns[i].first - pr;
        else if(s1 > 0 || s2 > 0) ns1 += sns[i].first - pr;
        if(sns[i].second == 1) s1++;
        if(sns[i].second == 2) s1--;
        if(sns[i].second == 3) s2++;
        if(sns[i].second == 4) s2--;
        pr = sns[i].first;
    }
    s1 = 0;
    s2 = 0;
    pr = 0;
    sns.clear();
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> l >> r;
        sns.push_back({l - 1, 1});
        sns.push_back({r, 2});
    }
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> l >> r;
        sns.push_back({l - 1, 3});
        sns.push_back({r, 4});
    }
    sort(sns.begin(), sns.end());
    for(int i = 0; i < sns.size(); i++) {
        if(s1 > 0 && s2 > 0) ew2 += sns[i].first - pr;
        else if(s1 > 0 || s2 > 0) ew1 += sns[i].first - pr;
        if(sns[i].second == 1) s1++;
        if(sns[i].second == 2) s1--;
        if(sns[i].second == 3) s2++;
        if(sns[i].second == 4) s2--;
        pr = sns[i].first;
    }
    ew0 = n - ew1 - ew2;
    ns0 = n - ns1 - ns2;
    cout << ew1 * ns0 + ew0 * ns1 << ' ';
    cout << ew1 * ns1 + ew0 * ns2 + ew2 * ns0 << ' ';
    cout << ew1 * ns2 + ew2 * ns1 << ' ';
    cout << ew2 * ns2;
    return 0;
}
