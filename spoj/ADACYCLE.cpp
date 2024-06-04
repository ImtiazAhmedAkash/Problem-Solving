/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ADACYCLE - Ada and Cycle

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
    vector<vector<int>> G(n, vector<int>());
    int x;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            cin >> x;
            if (x) {
                G[u].push_back(v);
            }
        }
    }

    auto bfs = [&](int src) -> int {
        vector<int> dist(n, inf);
        queue<int> Q;
        for (auto v : G[src]) {
            dist[v] = 1;
            Q.push(v);
        }

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            if (u == src) return dist[u];

            for (auto v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }

        return inf;
    };

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (auto v : G[i]) {
            if (v == i) {
                cout << 1 << nl;
                ok = true;
                break;
            }
        }
        if (ok) continue;

        int ans = bfs(i);
        if (ans == inf) {
            cout << "NO WAY" << nl;
        } else {
            cout << ans << nl;
        }
    }
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