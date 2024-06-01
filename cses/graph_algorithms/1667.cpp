/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Message Route

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
    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> dist(n + 1, inf);
    vector<int> nxt(n + 1);
    auto bfs = [&](int src) -> void {
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        nxt[src] = -1;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    nxt[v] = u;
                    Q.push(v);
                }
            }
        }
    };

    bfs(n);

    if (dist[1] == inf) {
        cout << "IMPOSSIBLE" << nl;
    } else {
        cout << 1 + dist[1] << nl;
        for (int x = 1; x != -1; x = nxt[x]) {
            cout << x << " ";
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