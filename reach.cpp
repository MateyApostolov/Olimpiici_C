#include <bits/stdc++.h>
using namespace std;

const int maxn = 5 * 1e4 + 1;
bool vis[maxn];
vector <int> graph[maxn];

int main () {
    int n, m, s, a, b, ans = 0;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    stack <int> st;
    st.push(s);
    vis[s] = true;
    while(!st.empty()) {
        int a = st.top();
        st.pop();
        vis[a] = true;
        for(auto b : graph[a]) {
            if(vis[b]) continue;
            st.push(b);
        }
    }
    priority_queue <pair<int, int>> rgr;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        bool vish[maxn] = {};
        stack <int> st;
        int br = 1;
        st.push(i);
        vish[i] = true;
        while(!st.empty()) {
            int a = st.top();
            st.pop();
            br++;
            vish[a] = true;
            for(auto b : graph[a]) {
                if(vish[b] || vis[a]) continue;
                st.push(b);
            }
        }
        rgr.push({br, i});
    }
    while(!rgr.empty()) {
        int pos = rgr.top().second;
        rgr.pop();
        if(vis[pos]) continue;
        ans++;
        stack <int> st;
        st.push(pos);
        vis[pos] = true;
        while(!st.empty()) {
            int a = st.top();
            st.pop();
            vis[a] = true;
            for(auto b : graph[a]) {
                if(vis[b]) continue;
                st.push(b);
            }
        }
    }
    cout << ans;
    return 0;
}
