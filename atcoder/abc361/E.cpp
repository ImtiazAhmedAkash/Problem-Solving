/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tree and Hamilton Path 2

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
    int n;
    cin >> n;
    vector G(n + 1, vector<pair<int, int>>());
    ll total = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        total += w;
    }

    vector<ll> dist(n + 1);
    auto dfs = [&](auto&& self, int u, int par) -> void {
        for (auto [v, w] : G[u]) {
            if (v == par) continue;
            dist[v] = dist[u] + w;
            self(self, v, u);
        }
    };

    dist[1] = 0;
    dfs(dfs, 1, 0);
    int node = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[node] = 0;
    dfs(dfs, node, 0);
    cout << 2 * total - *max_element(dist.begin(), dist.end()) << nl;
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