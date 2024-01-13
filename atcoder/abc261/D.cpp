/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Flipping and Bonus

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
    vector<int> X(n + 1);
    for (int i = 1; i <= n; i++) cin >> X[i];
    vector<int> bonus(n + 1);
    for (int i = 0; i < m; i++) {
        int c, y;
        cin >> c >> y;
        bonus[c] = y;
    }

    vector dp(n + 1, vector<ll>(n + 1, -1));
    auto fun = [&](auto&& self, int indx, int cnt) -> ll {
        if (indx == n + 1) return 0;
        if (~dp[indx][cnt]) return dp[indx][cnt];
        if (cnt) {
            return dp[indx][cnt] = X[indx] + bonus[cnt] + max(self(self, indx + 1, cnt + 1), self(self, indx + 1, 0));
        }
        return dp[indx][cnt] = max(self(self, indx + 1, 1), self(self, indx + 1, 0));
    };

    ll ans = fun(fun, 0, 0);
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