/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// EC_P - Critical Edges

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<pair<int, int>> bridge;
    vector<int> dist(n + 1), low(n + 1);
    int timer = 0;
    auto find_bridge = [&](auto&& self, int u, int par = 0) -> void {
        dist[u] = low[u] = ++timer;
        for (auto &v : G[u]) {
            if (v == par) continue;
            if (!dist[v]) {
                self(self, v, u);
                if (dist[u] < low[v]) {
                    int x = min(u, v);
                    int y = max(u, v);
                    bridge.push_back({x, y});
                }
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], dist[v]);
            }
        }
    };
    
    find_bridge(find_bridge, 1);
    
    if (bridge.empty()) {
        cout << "Sin bloqueos" << nl;
        return;
    }
    
    sort(bridge.begin(), bridge.end());
    cout << bridge.size() << nl;
    for (auto &[x, y] : bridge) {
        cout << x << " " << y << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Caso #" << t << nl;
        solve();
    }
    
    return 0;
}