/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// DISQUERY - Distance Query

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

const int LOG = 18;
vector<pair<int, int>> G[N + 5];
int up[N + 5][LOG + 5], mx[N + 5][LOG + 5], mn[N + 5][LOG + 5];
int depth[N + 5], tin[N + 5], tout[N + 5];
int timer = 0;

void dfs(int u, int p = 0, int w = 0) {
    up[u][0] = p;
    mx[u][0] = mn[u][0] = w;
    depth[u] = depth[p] + 1;
    tin[u] = ++timer;
    for (int i = 1; i <= LOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[up[u][i - 1]][i - 1]);
        mn[u][i] = min(mn[u][i - 1], mn[up[u][i - 1]][i - 1]);
    }
    for (auto &[v, w] : G[u]) {
        if (v != p) {
            dfs(v, u, w);
        }
    }
    tout[u] = ++timer;
}

pair<int, int> query(int u, int v) {
    int maxi = 0, mini = inf;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG; i >= 0; i--) {
        if (depth[up[u][i]] >= depth[v]) {
            maxi = max(maxi, mx[u][i]);
            mini = min(mini, mn[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return {mini, maxi};
    for (int i = LOG; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            maxi = max({maxi, mx[u][i], mx[v][i]});
            mini = min({mini, mn[u][i], mn[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    maxi = max({maxi, mx[u][0], mx[v][0]});
    mini = min({mini, mn[u][0], mn[v][0]});
    return {mini, maxi};
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dfs(1);
    
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        auto ans = query(u, v);
        cout << ans.first << " " << ans.second << nl;
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