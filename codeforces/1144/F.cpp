/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Graph Without Long Directed Paths

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
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        edges[i] = {u, v};
    }

    vector<int> color(n + 1, -1);
    bool bad = false;

    auto dfs = [&](auto &&self, int u, int col) -> void {
        color[u] = col;
        for (auto &v : G[u]) {
            if (color[v] == -1) {
                self(self, v, 1 - col);
            } else if (color[v] == col) {
                bad = true;
            }
        }
    };

    dfs(dfs, 1, 0);

    if (bad) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
    string ans;
    for (auto &[x, y] : edges) {
        ans += (color[x] < color[y] ? '0' : '1');
    }
    cout << ans << nl;
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