/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bear and Friendship Condition

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
    vector<int> G[n + 1];
    vector<bool> used(n + 1, false);
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int node = 0, edge = 0;

    function<void(int)> dfs = [&](int u) -> void {
        node++;
        used[u] = true;
        for (auto v : G[u]) {
            edge++;
            if (!used[v]) {
                dfs(v);
            }
        }
    };

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        dfs(i);
        ll need = 1LL * node * (node - 1);
        if (need != edge) {
            ok = false;
            break;
        }
        node = edge = 0;
    }
    cout << (ok ? "YES" : "NO") << nl;
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