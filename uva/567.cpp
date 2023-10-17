/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Risk

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 21;
static int t = 1;

void solve() {
    int n;
    while (cin >> n) {
        vector<int> G[N];
        for (int u = 1; u < 20; u++) {
            if (u != 1) cin >> n;
            while (n--) {
                int v;
                cin >> v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }

        auto bfs = [&](int src, int target) {
            vector<int> dist(N, -1);
            dist[src] = 0;
            queue<int> Q;
            Q.push(src);
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (auto v : G[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        Q.push(v);
                    }
                }
            }
            return dist[target];
        };
        
        cout << "Test Set #" << t++ << nl;

        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            int ans = bfs(x, y);
            cout << setw(2) << x << " to " << setw(2) << y << ": " << ans << nl;
        }
        cout << nl;
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