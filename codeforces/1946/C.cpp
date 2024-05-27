/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tree Cutting

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
    int n, k;
    cin >> n >> k;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto check = [&](int mid) -> bool {
        int component = 0;
        vector<int> subtree(n + 1);

        auto dfs = [&](auto&& self, int u, int par = -1) -> void {
            subtree[u]++;
            for (auto v : G[u]) {
                if (v == par) continue;
                self(self, v, u);
                subtree[u] += subtree[v];
            }
            if (subtree[u] >= mid) {
                component++;
                subtree[u] = 0;
            }
        };

        dfs(dfs, 1);
        return k + 1 <= component;
    };

    int L = 1, R = n / (k + 1);
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    cout << R << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}