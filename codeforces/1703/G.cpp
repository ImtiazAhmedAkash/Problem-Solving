/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Good Key, Bad Key

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 2e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector dp(n + 1, vector<ll>(35, -INF));
    auto fun = [&](auto&& self, int indx, int bit) -> ll {
        if (indx == n) return 0;
        auto& ans = dp[indx][bit];
        if (ans != -INF) return ans;

        int cur = A[indx] / (1 << bit);
        ans = max(ans, (cur / 2) + self(self, indx + 1, min(30, bit + 1)));
        ans = max(ans, (cur - k) + self(self, indx + 1, bit));

        return ans;
    };

    cout << fun(fun, 0, 0) << nl;
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