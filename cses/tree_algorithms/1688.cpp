/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Company Queries II

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

const int LOG = 18;
vector<vector<int>> G(N + 5);
vector up(N + 5, vector<int>(LOG + 5));
vector<int> depth(N + 5), tin(N + 5), tout(N + 5);
int timer = 0;

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

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

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

void solve() {
    int n, q;
    cin >> n >> q;
    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1);
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << nl;
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