/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// TOPOSORT - Topological Sorting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1, vector<int>());
    vector<int> indegree(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        indegree[v]++;
    }
    
    set<int> st;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            st.insert(i);
        }
    }
    
    vector<int> ans;
    while (!st.empty()) {
        auto u = *st.begin();
        st.erase(st.begin());
        ans.push_back(u);
        
        for (auto &v : G[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                st.insert(v);
            }
        }
    }
    
    if (ans.size() != n) {
        cout << "Sandro fails." << nl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}