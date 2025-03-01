/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Trapmigiano Reggiano

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, src, dest;
    cin >> n >> src >> dest;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<int> par(n + 1, 0);
    auto dfs1 = [&](auto&& self, int u, int p = 0) -> void {
        par[u] = p;
        for (auto &v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
        }
    };
    dfs1(dfs1, dest);
    
    vector<bool> used(n + 1, false);
    vector<int> ans;
    auto dfs2 = [&](auto&& self, int u, int p = 0) -> void {
        used[u] = true;
        for (auto &v : G[u]) {
            if (v == p) continue;
            if (!used[v]) self(self, v, u);
        }
        ans.push_back(u);
    };
    while (src != 0) {
        dfs2(dfs2, src, par[src]);
        src = par[src];
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
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