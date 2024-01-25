/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1009 - Back to Underworld

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e4 + 5;

vector<int> G[N];
vector<bool> vis(N, false);

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    while (n--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        mx = max({mx, u, v});
    }
    vector<int> dist(mx + 1, 0);
    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        if (vis[i] || G[i].empty()) continue;
        vector<int> A(2, 0);
        queue<int> Q;
        Q.push(i);
        vis[i] = true;
        dist[i] = 1;
        A[(dist[i] % 2)]++;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (vis[v]) continue;
                Q.push(v);
                vis[v] = true;
                dist[v] = dist[u] + 1;
                A[(dist[v] % 2)]++;
            }
        }
        ans += max(A.front(), A.back());
    }
    cout << ans << nl;
    
    for (int i = 1; i <= mx; i++) {
        G[i].clear();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}