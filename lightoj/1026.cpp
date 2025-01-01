/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Critical Links

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
    int n;
    cin >> n;
    vector G(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u;
        string s;
        cin >> u >> s;
        s.pop_back();
        int m = stoi(s.substr(1));
        while (m--) {
            int v;
            cin >> v;
            G[u].push_back(v);
        }
    }
    
    vector<int> dist(n), low(n);
    int timer = 0;
    vector<pair<int, int>> bridge;
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
    
    for (int i = 0; i < n; i++) {
        if (!dist[i]) {
            find_bridge(find_bridge, i);
        }
    }
    
    sort(bridge.begin(), bridge.end());
    
    cout << bridge.size() << " critical links" << nl;
    for (auto &[x, y] : bridge) {
        cout << x << " - " << y << nl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ":" << nl;
        solve();
    }
    
    return 0;
}