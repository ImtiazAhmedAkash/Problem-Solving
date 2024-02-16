/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1263 - Equalizing Money

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
    vector<int> A(n + 1);
    int total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        total += A[i];
    }
    vector G(n + 1, vector<int>());
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (total % n) {
        cout << "No" << nl;
        return;
    }

    int k = total / n;
    int cur = 0, cnt = 0;
    vector<bool> used(n + 1, false);

    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        cnt++;
        cur += A[u];
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    for (int u = 1; u <= n; u++) {
        if (!used[u]) {
            cur = 0, cnt = 0;
            dfs(dfs, u);
            if (cur % cnt || cur / cnt != k) {
                cout << "No" << nl;
                return;
            }
        }
    }
    cout << "Yes" << nl;
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