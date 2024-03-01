/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Super Takahashi Bros.

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
    vector G(n + 1, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        G[i].push_back({i + 1, a});
        G[i].push_back({x, b});
    }
    vector<ll> dist(n + 1, INF);
    auto dijkstra = [&](ll src) -> ll {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0LL, src});
        dist[src] = 0;
        while (!pq.empty()) {
            ll d = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            if (dist[u] != d) continue;
            for (auto it : G[u]) {
                int v = it.first;
                int wt = it.second;
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n];
    };

    ll ans = dijkstra(1);
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