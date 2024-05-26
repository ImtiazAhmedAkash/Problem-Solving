/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Subordinates

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
    for (int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> subtree(n + 1);
    auto dfs = [&](auto&& self, int u, int par = -1) -> void {
        for (auto v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
            subtree[u] += 1 + subtree[v];
        }
    };

    dfs(dfs, 1);
    for (int i = 1; i <= n; i++) {
        cout << subtree[i] << " ";
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