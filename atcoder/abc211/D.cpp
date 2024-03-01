/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Number of Shortest paths

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<int>());
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> dist(n + 1, inf);
    vector<ll> ways(n + 1, 0);

    auto bfs = [&](int src) -> void {
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        ways[src] = 1;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    ways[v] = ways[u];
                    Q.push(v);
                } else if (dist[u] + 1 == dist[v]) {
                    ways[v] += ways[u];
                    ways[v] %= mod;
                }
            }
        }
    };

    bfs(1);
    cout << ways[n] << nl;
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