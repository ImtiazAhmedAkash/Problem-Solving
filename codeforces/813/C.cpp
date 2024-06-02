/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Tag Game

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
    int n, x;
    cin >> n >> x;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> max_depth(n + 1);
    vector<int> time(n + 1);
    auto dfs_depth = [&](auto&& self, int u, int par, int d) -> int {
        time[u] = d;
        int ans = d;
        for (auto v : G[u]) {
            if (v == par) continue;
            ans = max(ans, self(self, v, u, d + 1));
        }
        return max_depth[u] = ans;
    };

    dfs_depth(dfs_depth, 1, -1, 0);

    auto dfs_move = [&](auto&& self, int u, int par, int move) -> int {
        int ans = max_depth[u];
        for (auto v : G[u]) {
            if (v == par || time[v] <= move + 1) continue;
            ans = max(ans, self(self, v, u, move + 1));
        }
        return ans;
    };

    cout << 2 * dfs_move(dfs_move, x, -1, 0) << nl;
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