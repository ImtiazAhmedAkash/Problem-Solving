/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Round Dance

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
    vector<set<int>> G(n + 1);
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        G[u].insert(v);
        G[v].insert(u);
    }

    vector<bool> used(n + 1, false);
    auto dfs = [&](auto&& self, int u) -> bool {
        used[u] = true;
        bool ok = (G[u].size() == 2);
        for (auto v : G[u]) {
            if (!used[v]) {
                ok &= self(self, v);
            }
        }
        return ok;
    };

    int closed = 0, open = 0;
    for (int u = 1; u <= n; u++) {
        if (!used[u]) {
            bool degree_two = dfs(dfs, u);
            if (degree_two) {
                closed++;
            } else {
                open++;
            }
        }
    }

    int min_ans = closed;
    if (open) {
        min_ans++;
    }
    int max_ans = open + closed;
    cout << min_ans << " " << max_ans << nl;
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