/*  In the Name of ALLAH, the most gracious, the most merciful  */

// A Node Too Far

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 35;
static int t = 1;

void solve() {
    int n;
    while (cin >> n && n) {
        vector<int> G[N];
        int indx = 0;
        map<int, int> M;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            if (M.find(u) == M.end()) {
                M[u] = indx++;
            }
            u = M[u];
            if (M.find(v) == M.end()) {
                M[v] = indx++;
            }
            v = M[v];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        auto bfs = [&](int src, int power) {
            vector<int> dist(indx, -1);
            dist[src] = 0;
            queue<int> Q;
            Q.push(src);
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (auto v : G[u]) {
                    if (dist[v] == -1 && dist[u] + 1 <= power) {
                        Q.push(v);
                        dist[v] = dist[u] + 1;
                    }
                }
            }
            return count(dist.begin(), dist.end(), -1);
        };
        
        int node, TTL;
        while (cin >> node >> TTL) {
            if (!node && !TTL) break;
            int ans = bfs(M[node], TTL);
            cout << "Case " << t++ << ": " << ans << " nodes not reachable from node " << node << " with TTL = " << TTL << "." << nl;
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