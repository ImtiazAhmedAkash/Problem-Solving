/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ring road

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
    vector G(n + 1, vector<int>());
    vector cost(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(v);
        G[v].push_back(u);
        cost[v][u] = w;
    }

    vector<int> used(n + 1, false);
    auto dfs = [&](auto&& self, int u, int par) -> int {
        used[u] = true;
        int res = cost[par][u];
        for (auto v : G[u]) {
            if (v == par || used[v]) continue;
            res += self(self, v, u);
        }
        return res;
    };

    int ans = dfs(dfs, G[1].front(), 1);
    fill(used.begin(), used.end(), false);
    ans = min(ans, dfs(dfs, G[1].back(), 1));
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