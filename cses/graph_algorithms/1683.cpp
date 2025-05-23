/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Planets and Kingdoms

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
    vector G(n + 1, vector<int>());
    vector invG(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        invG[v].push_back(u);
    }
    
    vector<bool> used(n + 1, false);
    vector<int> order;
    auto topo_sort = [&](auto&& self, int u) -> void {
        used[u] = true;
        for (auto &v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
        order.push_back(u);
    };
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            topo_sort(topo_sort, i);
        }
    }
    reverse(order.begin(), order.end());
    
    fill(used.begin(), used.end(), false);
    vector<int> cur;
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        cur.push_back(u);
        for (auto &v : invG[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };
    
    int scc = 0;
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        if (!used[order[i]]) {
            cur.clear();
            dfs(dfs, order[i]);
            scc++;
            for (auto &x : cur) {
                ans[x] = scc;
            }
        }
    }
    
    cout << scc << nl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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