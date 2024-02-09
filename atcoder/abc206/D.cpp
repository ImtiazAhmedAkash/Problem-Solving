/*  In the Name of ALLAH, the most gracious, the most merciful  */

// KAIBUNsyo

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    vector G(N + 5, vector<int>());
    for (int i = 0; i < n / 2; i++) {
        if (A[i] != A[n - 1 - i]) {
            G[A[i]].push_back(A[n - 1 - i]);
            G[A[n - 1 - i]].push_back(A[i]);
        }
    }

    int cnt = 0;
    vector<bool> used(N + 5, false);
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        cnt++;
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    int ans = 0;
    for (int u = 1; u <= N; u++) {
        if (!used[u] && !G[u].empty()) {
            cnt = 0;
            dfs(dfs, u);
            ans += cnt - 1;
        }
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