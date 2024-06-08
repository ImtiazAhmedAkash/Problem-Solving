/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Flight Discount

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
    vector InvG(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        InvG[v].push_back({u, w});
    }

    auto dijkstra = [&](int src, bool inverse) -> vector<ll> {
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] != d) continue;

            if (inverse) {
                for (auto [v, w] : InvG[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            } else {
                for (auto [v, w] : G[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist;
    };

    auto pref = dijkstra(1, false);
    auto suff = dijkstra(n, true);

    ll ans = INF;
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : G[u]) {
            ans = min(ans, pref[u] + suff[v] + w / 2);
        }
    }
    cout << ans << nl;
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