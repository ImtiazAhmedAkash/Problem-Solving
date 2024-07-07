/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Counting Numbers

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
    ll a, b;
    cin >> a >> b;

    ll dp[20][11][2];
    string s = to_string(b);
    int n = s.size();

    auto fun = [&](auto&& self, int indx, int prev, int chance) -> ll {
        if (indx == n) return 1;
        auto& ans = dp[indx][prev][chance];
        if (ans != -1) return ans;

        ans = 0;
        int bound = (chance ? s[indx] - '0' : 9);
        for (int digit = 0; digit <= bound; digit++) {
            if (digit == prev) continue;
            int cur = digit;
            if (prev == 10 && cur == 0) cur = 10;
            ans += self(self, indx + 1, cur, chance & (digit == bound));
        }

        return ans;
    };

    memset(dp, -1, sizeof dp);
    ll R = fun(fun, 0, 10, 1);

    ll L = 0;
    if (a > 0) {
        s = to_string(a - 1);
        n = s.size();
        memset(dp, -1, sizeof dp);
        L = fun(fun, 0, 10, 1);
    }
    cout << R - L << nl;
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