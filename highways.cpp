#include <bits/stdc++.h>
using namespace std;

const int maxn = 5 * 1e4 + 1;
bool vis[maxn];
vector <int> graph[maxn];

int main () {
    int n, m, ans;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, diff;
        cin >> a >> b >> diff;
        if(diff == 0) {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        ans++;
        stack <int> st;
        st.push(i);
        vis[i] = true;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            for(auto v : graph[u]) {
                if(vis[v]) continue;
                st.push(v);
                vis[v] = true;
            }
        }
    }
    cout << --ans;
    return 0;
}
