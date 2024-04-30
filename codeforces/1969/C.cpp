/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimizing the Sum

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector dp(n, vector<ll>(k + 1, -1));
    auto fun = [&](auto&& self, int indx, int op) -> ll {
        if (indx == n) return 0;
        if (dp[indx][op] != -1) return dp[indx][op];

        ll ans = INF;
        int mini = A[indx];
        for (int i = indx; i < n && i - indx <= op; i++) {
            mini = min(mini, A[i]);
            int used = i - indx;
            ans = min(ans, 1LL * (used + 1) * mini + self(self, i + 1, op - used));
        }
        return dp[indx][op] = ans;
    };

    cout << fun(fun, 0, k) << nl;
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