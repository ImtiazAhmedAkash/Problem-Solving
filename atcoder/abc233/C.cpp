/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Product

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
    vector A(n, vector<int>());
    ll x;
    cin >> x;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        while (j--) {
            int k;
            cin >> k;
            A[i].push_back(k);
        }
    }
    int ans = 0;

    auto dfs = [&](auto&& self, int u, int row, ll cur) -> void {
        if (x % cur || x / cur < u) return;
        cur *= u;
        if (row + 1 == n) {
            if (cur == x) ans++;
            return;
        }
        for (auto z : A[row + 1]) {
            self(self, z, row + 1, cur);
        }
    };

    for (int i = 0; i < A[0].size(); i++) {
        dfs(dfs, A[0][i], 0, 1LL);
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