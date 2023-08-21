/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Who is Saikyo?

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 55
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

vector<int> g[N];
vector<bool> vis(N, false);

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : g[u]) {
        dfs(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        dfs(i);
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) cnt++;
            vis[j] = 0;
        }
        if (cnt == n) ans = i;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}