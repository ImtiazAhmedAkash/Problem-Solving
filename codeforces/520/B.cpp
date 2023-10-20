/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Buttons

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e4 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    
    auto bfs = [&] (int src) {
        vector<int> dist(N, -1);
        dist[src] = 0;
        queue<int> Q;
        Q.push(src);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            if (u == m) {
                cout << dist[u] << nl;
                return;
            }
            if (u - 1 > 0 && dist[u - 1] == -1) {
                dist[u - 1] = dist[u] + 1;
                Q.push(u - 1);
            }
            if (2 * u < N && dist[2 * u] == -1) {
                dist[2 * u] = dist[u] + 1;
                Q.push(2 * u);
            }
        }
    };
    
    bfs(n);
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