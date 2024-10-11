/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Expanding STACKS!

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
    int n;
    cin >> n;
    vector<int> A(2 * n);
    for (auto& x : A) cin >> x;

    vector<int> in(n + 1), out(n + 1);
    for (int i = 0; i < 2 * n; i++) {
        if (A[i] > 0) {
            in[A[i]] = i;
        } else {
            out[-A[i]] = i;
        }
    }

    vector G(n + 1, vector<int>());
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if ((in[u] < in[v] && in[v] < out[u] && out[u] < out[v]) ||
                (in[v] < in[u] && in[u] < out[v] && out[v] < out[u])) {
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
    }

    vector<int> color(n + 1, -1);
    bool ok = true;
    auto dfs = [&](auto&& self, int u, int col) -> void {
        color[u] = col;
        for (auto& v : G[u]) {
            if (color[v] == -1) {
                self(self, v, 1 - col);
            } else if (color[v] == col) {
                ok = false;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            dfs(dfs, i, 0);
        }
    }

    if (not ok) {
        cout << "*" << nl;
        return;
    }

    string ans;
    for (int i = 1; i <= n; i++) {
        ans += (color[i] ? 'G' : 'S');
    }
    cout << ans << nl;
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