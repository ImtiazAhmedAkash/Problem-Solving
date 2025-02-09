/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Game on Tree (Hard)

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
    int n, q;
    cin >> n >> q;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<int> dp(n + 1, -1);
    // dp[i] = 0 -> winning state
    // dp[i] = 1 -> losing state
    auto dfs = [&](auto&& self, int u, int par = -1) -> void {
        int sum = 0;
        for (auto &v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
            sum += dp[v];
        }
        dp[u] = (sum ? 0 : 1);
    };
    dfs(dfs, 1);
    
    vector<int> dp1(n + 1, -1);
    auto reroot = [&](auto&& self, int u, int par = -1, int carry = 0) -> void {
        dp1[u] = (!dp[u] || carry ? 0 : 1);
        
        int sum = carry;
        for (auto &v : G[u]) {
            if (v == par) continue;
            sum += dp[v];
        }
        
        for (auto &v : G[u]) {
            if (v == par) continue;
            sum -= dp[v];
            self(self, v, u, (sum ? 0 : 1));
            sum += dp[v];
        }
    };
    reroot(reroot, 1);
    
    while (q--) {
        int x;
        cin >> x;
        cout << (dp1[x] ? "Hermione" : "Ron") << nl;
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