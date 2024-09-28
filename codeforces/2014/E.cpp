/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Rendez-vous de Marian et Robin

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector G(n + 1, vector<pair<int, int>>());

    vector<int> H(n + 1, 1);
    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        H[x] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    //  dist[x][0] -> minimum time to reach vertex x with horse
    //  dist[x][1] -> minimum time to reach vertex x with no horse
    auto dijkstra = [&](int src) -> vector<vector<ll>> {
        vector dist(n + 1, vector<ll>(2, INF));
        min_heap<array<ll, 3>> pq;
        int nh = H[src];
        dist[src][nh] = 0;
        pq.push({0, src, nh});

        while (!pq.empty()) {
            auto [d, u, nh] = pq.top();
            pq.pop();

            if (dist[u][nh] != d) continue;

            for (auto &[v, w] : G[u]) {
                ll cur = dist[u][nh] + (nh ? w : w / 2);
                int curh = nh * H[v];
                if (cur < dist[v][curh]) {
                    dist[v][curh] = cur;
                    pq.push({cur, v, curh});
                }
            }
        }

        return dist;
    };

    auto A = dijkstra(1);
    auto B = dijkstra(n);

    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        ll cur = max(min(A[i][0], A[i][1]), min(B[i][0], B[i][1]));
        ans = min(ans, cur);
    }

    cout << (ans == INF ? -1 : ans) << nl;
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