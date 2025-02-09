/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Maximum White Subtree

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
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] == 0) A[i] = -1;
    }
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<int> dp(n + 1);
    auto dfs = [&](auto&& self, int u, int par = -1) -> void {
        dp[u] = A[u];
        for (auto &v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
            dp[u] += max(0, dp[v]);
        }
    };
    dfs(dfs, 1);
    
    vector<int> dp1(n + 1);
    auto reroot = [&](auto&& self, int u, int par = -1, int carry = 0) -> void {
        dp1[u] = dp[u] + carry;
        
        int sum = A[u] + carry;
        for (auto &v : G[u]) {
            if (v == par) continue;
            sum += max(0, dp[v]);
        }
        
        for (auto &v : G[u]) {
            if (v == par) continue;
            sum -= max(0, dp[v]);
            self(self, v, u, max(0, sum));
            sum += max(0, dp[v]);
        }
    };
    reroot(reroot, 1);
    
    for (int i = 1; i <= n; i++) {
        cout << dp1[i] << " \n"[i == n];
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