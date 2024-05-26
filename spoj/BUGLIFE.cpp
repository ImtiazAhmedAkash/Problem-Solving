/*  In the Name of ALLAH, the most gracious, the most merciful  */

// BUGLIFE - A Bug’s Life

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
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool ok = true;
    vector<int> color(n + 1, -1);
    auto dfs = [&](auto&& self, int u, int c) -> void {
        color[u] = c;
        for (auto v : G[u]) {
            if (color[v] == -1) {
                self(self, v, 1 - c);
            } else if (color[v] == c) {
                ok = false;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            dfs(dfs, i, 0);
        }
    }

    cout << (ok ? "No suspicious bugs found!" : "Suspicious bugs found!") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Scenario #" << t << ":" << nl;
        solve();
    }

    return 0;
}