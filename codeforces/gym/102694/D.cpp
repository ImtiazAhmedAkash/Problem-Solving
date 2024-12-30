/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Cycle Free Flow

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e5;

const int LOG = 18;

vector<pair<int, int>> G[N + 5];
int up[N + 5][LOG + 5], flow[N + 5][LOG + 5];
int depth[N + 5], tin[N + 5], tout[N + 5];
int timer = 0;

void dfs(int u, int p = 0, int wt = 0) {
    up[u][0] = p;
    flow[u][0] = wt;
    depth[u] = depth[p] + 1;
    tin[u] = ++timer;
    for (int i = 1; i <= LOG; i++) {
        flow[u][i] = min(flow[u][i - 1], flow[up[u][i - 1]][i - 1]);
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto &[v, w] : G[u]) {
        if (v != p) {
            dfs(v, u, w);
        }
    }
    tout[u] = ++timer;
}
int lca_max_flow(int u, int v) {
    int ans = inf;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG; i >= 0; i--) {
        if (depth[up[u][i]] >= depth[v]) {
            ans = min(ans, flow[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return ans;
    for (int i = LOG; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            ans = min({ans, flow[u][i], flow[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    return min({ans, flow[u][0], flow[v][0]});
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dfs(1);
    
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca_max_flow(u, v) << nl;
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