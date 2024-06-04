/*  In the Name of ALLAH, the most gracious, the most merciful  */

// DIGOKEYS - Find the Treasure

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
    vector<vector<int>> G(n + 1, vector<int>());
    for (int u = 1; u < n; u++) {
        int x;
        cin >> x;
        while (x--) {
            int v;
            cin >> v;
            G[u].push_back(v);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        sort(G[i].begin(), G[i].end());
    }
    
    vector<int> dist(n + 1, inf);
    vector<int> par(n + 1, -1);
    auto bfs = [&](int src) -> void {
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            
            if (dist[n] != inf) return;
            
            for (auto v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    Q.push(v);
                }
            }
        }
    };
    
    bfs(1);
    if (dist[n] == inf) {
        cout << -1 << nl;
        return;
    }
    
    vector<int> path;
    for (int i = par[n]; i != -1; i = par[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    
    cout << dist[n] << nl;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i + 1 == path.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
        cout << nl;
    }
    
    return 0;
}