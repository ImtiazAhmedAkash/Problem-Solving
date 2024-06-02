/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Little Alawn's Puzzle

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        G[A[i]].push_back(v);
        G[v].push_back(A[i]);
    }

    int component = 0;
    vector<bool> used(n + 1, false);
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(dfs, i);
            component++;
        }
    }

    int ans = 1;
    for (int i = 1; i <= component; i++) {
        ans = (2LL * ans) % mod;
    }
    cout << ans << nl;
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