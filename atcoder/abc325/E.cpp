/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Our clients, please wait a moment

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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector G(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> G[i][j];
        }
    }

    auto dijkstra = [&](int src, bool car) -> vector<ll> {
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] != d) continue;

            for (int v = 1; v <= n; v++) {
                if (car) {
                    if (dist[u] + 1LL * G[u][v] * a < dist[v]) {
                        dist[v] = dist[u] + 1LL * G[u][v] * a;
                        pq.push({dist[v], v});
                    }
                } else {
                    if (dist[u] + 1LL * G[u][v] * b + c < dist[v]) {
                        dist[v] = dist[u] + 1LL * G[u][v] * b + c;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        return dist;
    };

    auto car = dijkstra(1, true);
    auto train = dijkstra(n, false);

    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, car[i] + train[i]);
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