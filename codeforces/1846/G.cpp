/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Rudolf and CodeVid-23

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> cost(m);
    vector<string> good(m), bad(m);
    for (int i = 0; i < m; i++) {
        cin >> cost[i] >> good[i] >> bad[i];
        reverse(good[i].begin(), good[i].end());
        reverse(bad[i].begin(), bad[i].end());
    }

    int src = 0;
    reverse(s.begin(), s.end());
    for (int bit = 0; bit < n; bit++) {
        if (s[bit] == '1') {
            src += (1 << bit);
        }
    }

    vector<vector<pair<int, int>>> G((1 << n), vector<pair<int, int>>());
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < m; i++) {
            int cur = mask;
            for (int bit = 0; bit < n; bit++) {
                if (good[i][bit] == '1') {
                    cur &= (~(1 << bit));
                }
                if (bad[i][bit] == '1') {
                    cur |= (1 << bit);
                }
            }
            G[mask].push_back({cur, cost[i]});
        }
    }

    vector<int> dist((1 << n), inf);
    dist[src] = 0;
    min_heap<pair<int, int>> pq;
    pq.push({dist[src], src});

    while (!pq.empty()) {
        auto [cdist, u] = pq.top();
        pq.pop();

        if (dist[u] != cdist) continue;

        for (auto &[v, w] : G[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << (dist[0] == inf ? -1 : dist[0]) << nl;
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