/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bonus EXP

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    vector dp(n + 5, vector<ll>(3, -1));
    auto fun = [&](auto &&self, int indx, int isEven) -> ll {
        if (indx == n) return 0;
        auto &ans = dp[indx][isEven];
        if (ans != -1) return ans;

        ans = self(self, indx + 1, isEven);
        ans = max(ans, A[indx] + (isEven ? A[indx] : 0) + self(self, indx + 1, !isEven));

        return ans;
    };

    cout << fun(fun, 0, 0) << nl;
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