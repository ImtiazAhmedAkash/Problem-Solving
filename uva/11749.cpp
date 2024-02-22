/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11749 - Poor Trade Advisor

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
    while (cin >> n >> m && n && m) {
        vector<array<int, 3>> A;
        int mx_profit = INT_MIN;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            mx_profit = max(mx_profit, w);
            A.push_back({w, u, v});
        }

        vector<vector<int>> G(n + 1);
        for (int i = 0; i < A.size(); i++) {
            auto [w, u, v] = A[i];
            if (w == mx_profit) {
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }

        vector<bool> used(n + 1, false);
        auto bfs = [&](int src) -> int {
            int cnt = 0;
            queue<int> Q;
            Q.push(src);
            used[src] = true;
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                cnt++;
                for (auto v : G[u]) {
                    if (!used[v]) {
                        used[v] = true;
                        Q.push(v);
                    }
                }
            }
            return cnt;
        };

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                ans = max(ans, bfs(i));
            }
        }
        cout << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}