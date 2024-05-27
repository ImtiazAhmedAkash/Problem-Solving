/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ichigo and Part Time Job

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
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> subtree(n + 1), depth(n + 1);
    auto dfs = [&](auto&& self, int u, int d, int par = -1) -> void {
        depth[u] = d;
        for (auto v : G[u]) {
            if (v == par) continue;
            self(self, v, d + 1, u);
            if (A[v] || subtree[v]) {
                subtree[u] += 2 + subtree[v];
            }
        }
    };

    dfs(dfs, 1, 0);

    while (q--) {
        int x;
        cin >> x;
        cout << (subtree[x] == 0 && A[x] == 0 ? 0 : subtree[x] + 2 * depth[x]) << nl;
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