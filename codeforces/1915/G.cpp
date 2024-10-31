/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Bicycles

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1000;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<int> bike(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> bike[i];
    }

    ll ans = INF;
    min_heap<array<ll, 3>> pq;
    vector dist(n + 1, vector<ll>(N + 5, INF));
    dist[1][bike[1]] = 0;
    pq.push({0, bike[1], 1});

    while (!pq.empty()) {
        auto [cdist, s, u] = pq.top();
        pq.pop();

        for (auto &[v, w] : G[u]) {
            if (cdist + s * w < dist[v][s]) {
                dist[v][s] = cdist + s * w;
                int ns = min((int)s, bike[v]);
                pq.push({dist[v][s], ns, v});
                if (v == n) {
                    ans = min(ans, dist[v][s]);
                }
            }
        }
    }

    cout << ans << nl;
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