/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bear and Three Musketeers

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
    vector C(n + 1, vector(n + 1, 0));
    vector<int> G[n + 1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        C[u][v] = C[v][u] = 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = inf;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() < 2) continue;
        for (int j = 0; j < G[i].size(); j++) {
            for (int k = j + 1; k < G[i].size(); k++) {
                int sm = G[i][j], tm = G[i][k];
                if (C[sm][tm] == 1) {
                    ans = min(ans, (int)(G[i].size() + G[sm].size() + G[tm].size()) - 6);
                }
            }
        }
    }
    cout << (ans == inf ? -1 : ans) << nl;
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