/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Counting Paths

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

const int LOG = 18;

vector<int> G[N + 5];
int up[N + 5][LOG + 5];
int depth[N + 5], tin[N + 5], tout[N + 5];
int timer = 0;

// builds the up[][] table for LCA
void dfs(int u, int p = 0) {
    up[u][0] = p;
    depth[u] = depth[p] + 1;
    tin[u] = ++timer;
    for (int i = 1; i <= LOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto &v : G[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

// checks whether u is an ancestor of v
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// returns the LCA of u and v
int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG; i >= 0; i--) {
        if (depth[up[u][i]] >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

// returns the distance between u and v
int dist_uv(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

// returns the k-th ancestor of u
int kth_ancestor(int u, int k) {
    if (depth[u] <= k) return -1;
    for (int i = LOG; i >= 0; i--) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

// returns the k-th node in the path between u and v
int kth_in_path(int u, int v, int k) {
    int l = lca(u, v);
    int d = depth[u] + depth[v] - 2 * depth[l];
    if (k > d) return -1;
    if (depth[l] + k <= depth[u]) return kth_ancestor(u, k);
    k -= depth[u] - depth[l];
    return kth_ancestor(v, depth[v] - depth[l] - k);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1);
    
    vector<int> ans(n + 1, 0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        int lc = lca(u, v);
        ans[u]++;
        ans[v]++;
        ans[lc]--;
        ans[up[lc][0]]--;
    }
    
    auto dfs_sum = [&](auto&& self, int u, int par = 0) -> void {
        for (auto &v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
            ans[u] += ans[v];
        }
    };
    dfs_sum(dfs_sum, 1);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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