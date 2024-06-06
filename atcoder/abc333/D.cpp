/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Erase Leaves

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int cnt = 0;
    auto dfs = [&](auto self, int u, int par) -> void {
        cnt++;
        for (auto v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
        }
    };

    vector<int> Component;
    for (auto v : G[1]) {
        cnt = 0;
        dfs(dfs, v, 1);
        Component.push_back(cnt);
    }
    sort(Component.begin(), Component.end());
    Component.pop_back();
    int ans = 1;
    for (auto x : Component) {
        ans += x;
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