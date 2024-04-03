/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Building Roads

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
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<bool> used(n + 1, false);
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };
    
    vector<pair<int, int>> ans;
    dfs(dfs, 1);
    for (int u = 2; u <= n; u++) {
        if (!used[u]) {
            dfs(dfs, u);
            ans.push_back({1, u});
        }
    }
    cout << ans.size() << nl;
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << nl;
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