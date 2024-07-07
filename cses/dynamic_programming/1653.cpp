/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Elevator Rides

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> W(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }

    vector<pair<int, int>> dp(1 << n, {-1, 0});
    // dp[mask].first = minimum no. of elevator rides to carry the persons of this mask
    // dp[mask].second = minimum sum of weights in the last ride of this mask

    auto fun = [&](auto&& self, int mask) -> pair<int, int> {
        if (mask == 0) return {1, 0};
        if (dp[mask].first != -1) return dp[mask];

        pair<int, int> ans = {inf, inf};
        for (int bit = 0; bit < n; bit++) {
            if ((mask & (1 << bit)) == 0) continue;

            auto res = self(self, mask ^ (1 << bit));
            if (res.second + W[bit] <= x) {
                res.second += W[bit];
            } else {
                res.first++;
                res.second = W[bit];
            }
            ans = min(ans, res);
        }

        return dp[mask] = ans;
    };

    cout << fun(fun, (1 << n) - 1).first << nl;
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