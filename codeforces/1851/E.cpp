/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Natsya and Potions

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> cost(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    while (m--) {
        int x;
        cin >> x;
        cost[x] = 0;
    }
    vector<int> g[n + 1];
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (x--) {
            int v;
            cin >> v;
            g[i].push_back(v);
        }
    }
    function<ll(int)> dfs = [&](int u) {
        if (vis[u]) return cost[u];
        vis[u] = true;
        if (g[u].empty()) return cost[u];
        ll cur = 0;
        for (auto v : g[u]) {
            cur += dfs(v);
        }
        return cost[u] = min(cost[u], cur);
    };
    for (int i = 1; i <= n; i++) {
        cost[i] = dfs(i);
        cout << cost[i] << " ";
    }
    cout << nl;
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