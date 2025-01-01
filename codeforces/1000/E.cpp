/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// We Need More Bosses

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
    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    set<pair<int, int>> bridge;
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
                    bridge.insert({x, y});
                }
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], dist[v]);
            }
        }
    };
    
    find_bridge(find_bridge, 1);
    
    vector<int> component(n + 1, -1);
    int compId = 0;
    auto dfs_component = [&](auto&& self, int u) -> void {
        component[u] = compId;
        for (auto &v : G[u]) {
            if (component[v] == -1 && bridge.find(make_pair(min(u, v), max(u, v))) == bridge.end()) {
                self(self, v);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (component[i] == -1) {
            compId++;
            dfs_component(dfs_component, i);
        }
    }
    
    vector BG(compId + 1, vector<int>());
    for (auto &[x, y] : bridge) {
        int u = component[x];
        int v = component[y];
        BG[u].push_back(v);
        BG[v].push_back(u);
    }
    
    auto bfs_diameter = [&](int src, vector<int>& dist) -> int {
        dist.assign(compId + 1, inf);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int last = src;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (auto &v : BG[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            last = u;
        }
        return last;
    };
    
    vector<int> D;
    int x = bfs_diameter(1, D);
    bfs_diameter(x, D);
    
    cout << *max_element(D.begin() + 1, D.end()) << nl;
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