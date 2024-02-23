/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11686 - Pick up sticks

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
    while (cin >> n >> m && n) {
        vector<vector<int>> G(n + 1, vector<int>());
        while (m--) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
        }

        vector<bool> used(n + 1, false);
        vector<bool> inDFS(n + 1, false);
        stack<int> ans;

        function<bool(int)> dfs = [&](int u) -> bool {
            used[u] = true;
            inDFS[u] = true;
            for (auto v : G[u]) {
                if (used[v] && inDFS[v]) {
                    return true;
                }
                if (!used[v] && dfs(v)) {
                    return true;
                }
            }
            inDFS[u] = false;
            ans.push(u);
            return false;
        };

        bool bad = false;
        for (int u = 1; u <= n; u++) {
            if (!used[u]) {
                bad |= dfs(u);
            }
        }

        if (bad) {
            cout << "IMPOSSIBLE" << nl;
            continue;
        }

        while (!ans.empty()) {
            cout << ans.top() << nl;
            ans.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}