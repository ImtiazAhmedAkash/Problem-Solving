/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Path Graph?

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

    int child_node = 0;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 1) {
            child_node = i;
            break;
        }
    }

    bool ok = true;
    int total = 0;
    vector<bool> used(n + 1, false);

    auto dfs = [&](auto self, int u, int par = -1) -> void {
        used[u] = true;
        total++;
        int cnt = 0;
        for (auto v : G[u]) {
            if (par == v) continue;
            if (used[v]) {
                ok = false;
            } else {
                cnt++;
                self(self, v, u);
                if (cnt == 2) ok = false;
            }
        }
    };

    dfs(dfs, child_node);
    cout << (ok && total == n ? "Yes" : "No") << nl;
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