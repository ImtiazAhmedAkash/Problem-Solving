/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Remove the Bracket

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
    int n, s;
    cin >> n >> s;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector dp(n + 1, vector<ll>(2, -1));
    auto fun = [&](auto&& self, int indx, int choice, int prev) -> ll {
        if (indx == n - 1) return 1LL * prev * A[indx];
        auto& ans = dp[indx][choice];
        if (~ans) return ans;

        ll x = 0, y = A[indx];
        if (s < A[indx]) {
            x = s;
            y = A[indx] - s;
        }

        ans = 1LL * prev * x + self(self, indx + 1, 1, y);
        ans = min(ans, 1LL * prev * y + self(self, indx + 1, 0, x));

        return ans;
    };

    cout << fun(fun, 1, 0, A[0]) << nl;
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