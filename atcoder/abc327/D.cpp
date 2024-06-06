/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Good Tuple Problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> S(m);
    for (auto& x : S) cin >> x;
    vector<int> T(m);
    for (auto& x : T) cin >> x;

    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        G[S[i]].push_back(T[i]);
        G[T[i]].push_back(S[i]);
    }

    bool ok = true;
    vector<int> color(n + 1, -1);

    auto dfs = [&](auto self, int u, int c) -> void {
        color[u] = c;
        for (auto v : G[u]) {
            if (color[v] == color[u]) {
                ok = false;
            }
            if (color[v] == -1) {
                self(self, v, 1 - c);
            }
        }
    };

    for (int u = 1; u <= n; u++) {
        if (color[u] == -1) {
            dfs(dfs, u, 0);
        }
    }

    cout << (ok ? "Yes" : "No") << nl;
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