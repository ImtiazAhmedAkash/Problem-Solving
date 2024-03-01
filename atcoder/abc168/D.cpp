/*  In the Name of ALLAH, the most gracious, the most merciful  */

// .. (Double Dots)

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
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (G[1].empty()) {
        cout << "No" << nl;
        return;
    }

    cout << "Yes" << nl;

    vector<int> ans(n + 1, -1);
    auto bfs = [&](int src) -> void {
        queue<int> Q;
        Q.push(src);
        ans[src] = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (ans[v] != -1) continue;
                ans[v] = u;
                Q.push(v);
            }
        }
    };

    bfs(1);
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << nl;
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