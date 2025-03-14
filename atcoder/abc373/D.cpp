/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Hidden Weights

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
    vector G(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, -w});
    }
    
    vector<ll> ans(n + 1);
    vector<bool> used(n + 1, false);
    
    auto dfs = [&](auto&& self, int u, ll cost) -> void {
        used[u] = true;
        ans[u] = cost;
        for (auto &[v, w] : G[u]) {
            if (!used[v]) {
                self(self, v, cost + w);
            }
        }
    };
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(dfs, i, 0);
        }
    }
    
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