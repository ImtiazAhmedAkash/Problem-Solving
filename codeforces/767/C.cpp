/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Garland

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
    vector<int> wt(n + 1);
    int sum = 0;
    int root = 0;
    for (int u = 1; u <= n; u++) {
        int v, w;
        cin >> v >> w;
        if (v == 0) {
            root = u;
        } else {
            G[u].push_back(v);
            G[v].push_back(u);
        }
        wt[u] = w;
        sum += w;
    }

    if (sum % 3) {
        cout << -1 << nl;
        return;
    }

    vector<int> subtree(n + 1, 0);
    vector<int> ans;
    auto dfs = [&](auto&& self, int u, int par = 0) -> int {
        for (auto& v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
            if (subtree[v] == (sum / 3)) {
                subtree[v] = 0;
                ans.push_back(v);
            }
            subtree[u] += subtree[v];
        }
        return subtree[u] += wt[u];
    };

    dfs(dfs, root);

    if (ans.size() < 2) {
        cout << -1 << nl;
    } else {
        cout << ans[0] << " " << ans[1] << nl;
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