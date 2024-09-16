/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Jellyfish and Mex

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
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n) {
            cnt[x]++;
        }
    }
    int mex = 0;
    while (cnt[mex]) mex++;

    vector<int> dp(mex + 1, -1);
    auto fun = [&](auto&& self, int m) -> int {
        if (m == 0) return 0;
        auto& ans = dp[m];
        if (~ans) return ans;

        ans = inf;
        for (int i = m - 1; i >= 0; i--) {
            ans = min(ans, self(self, i) + (cnt[i] - 1) * m + i);
        }
        return ans;
    };

    cout << fun(fun, mex) << nl;
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