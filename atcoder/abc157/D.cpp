/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Friend Suggestions

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
    int n, m, k;
    cin >> n >> m >> k;
    vector G(n + 1, vector<int>());
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector B(n + 1, vector<int>());
    while (k--) {
        int u, v;
        cin >> u >> v;
        B[u].push_back(v);
        B[v].push_back(u);
    }

    vector<bool> used(n + 1, false);
    set<int> connected;
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        connected.insert(u);
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    vector<int> ans(n + 1);
    for (int u = 1; u <= n; u++) {
        if (used[u]) continue;
        connected.clear();
        dfs(dfs, u);
        for (auto x : connected) {
            int candidate = (int)connected.size() - (int)G[x].size() - 1;
            int blocked = 0;
            for (auto y : B[x]) {
                if (connected.find(y) != connected.end()) blocked++;
            }
            ans[x] = candidate - blocked;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
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