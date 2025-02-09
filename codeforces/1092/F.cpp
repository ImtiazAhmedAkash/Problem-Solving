/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Tree with Maximum Cost

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
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        total += A[i];
    }
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<ll> subtree_sum(n + 1), subtree_cost(n + 1);
    auto dfs = [&](auto&& self, int u, int par = -1) -> void {
        subtree_sum[u] = A[u];
        for (auto &v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
            subtree_sum[u] += subtree_sum[v];
            subtree_cost[u] += subtree_cost[v] + subtree_sum[v];
        }
    };
    dfs(dfs, 1);
    
    vector<ll> ans(n + 1);
    auto reroot = [&](auto&& self, int u, int par = -1, ll carry = 0) -> void {
        ans[u] = subtree_cost[u] + carry;
        
        ll sum = carry;
        for (auto &v : G[u]) {
            if (v == par) continue;
            sum += subtree_cost[v] + subtree_sum[v];
        }
        
        for (auto &v : G[u]) {
            if (v == par) continue;
            sum -= (subtree_sum[v] + subtree_cost[v]);
            sum += (total - subtree_sum[v]);
            self(self, v, u, sum);
            sum += (subtree_sum[v] + subtree_cost[v]);
            sum -= (total - subtree_sum[v]);
        }
    };
    reroot(reroot, 1);
    
    cout << *max_element(ans.begin(), ans.end()) << nl;
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