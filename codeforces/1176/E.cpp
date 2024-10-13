/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Cover it!

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

    vector<int> color(n + 1, -1);
    vector<int> even, odd;
    auto dfs = [&](auto &&self, int u, int col) -> void {
        color[u] = col;
        if (col & 1) {
            odd.push_back(u);
        } else {
            even.push_back(u);
        }
        for (auto &v : G[u]) {
            if (color[v] == -1) {
                self(self, v, 1 - col);
            }
        }
    };

    dfs(dfs, 1, 0);

    if (even.size() <= odd.size()) {
        cout << even.size() << nl;
        for (auto &x : even) {
            cout << x << " ";
        }
    } else {
        cout << odd.size() << nl;
        for (auto &x : odd) {
            cout << x << " ";
        }
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}