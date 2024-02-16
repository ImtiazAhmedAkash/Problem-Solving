/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1019 - Brush (V)

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
    vector G(n + 1, vector<pair<int, int>>());
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<int> dist(n + 1, inf);
    auto bfs = [&](int src) -> void {
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto [v, wt] : G[u]) {
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    Q.push(v);
                }
            }
        }
    };

    bfs(1);
    if (dist[n] == inf) {
        cout << "Impossible" << nl;
    } else {
        cout << dist[n] << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}