/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Round Trip

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

    vector<int> used(n + 1, false);
    vector<int> ans;
    stack<int> stk;
    auto dfs = [&](auto&& self, int u, int par = -1) -> bool {
        used[u] = true;
        stk.push(u);

        for (auto v : G[u]) {
            if (used[v] && v != par) {
                ans.push_back(v);
                return true;
            } else if (!used[v] && self(self, v, u)) {
                return true;
            }
        }

        stk.pop();
        return false;
    };

    for (int u = 1; u <= n; u++) {
        if (!used[u]) {
            bool ok = dfs(dfs, u);
            if (ok) {
                while (stk.top() != ans.front()) {
                    ans.push_back(stk.top());
                    stk.pop();
                }
                ans.push_back(stk.top());

                cout << ans.size() << nl;
                for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i] << " \n"[i + 1 == ans.size()];
                }
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << nl;
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