/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Hits Different

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

vector<ll> dp(N + 5, -1);

void solve() {
    int n;
    cin >> n;

    int L = 0, R = 1e4;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (M * (M + 1) / 2 >= n) {
            R = M;
        } else {
            L = M + 1;
        }
    }

    auto fun = [&](auto&& self, int val, int row) -> ll {
        if (val <= 0) return 0;
        auto& ans = dp[val];
        if (~ans) return ans;

        ans = 1LL * val * val;

        // boundary of previous row
        int r = row * (row - 1) / 2;
        int l = r - (row - 1) + 1;

        int cnt = 0;
        int left = val - row;
        if (l <= left && left <= r) {
            cnt++;
            ans += self(self, left, row - 1);
        }

        int right = val - row + 1;
        if (l <= right && right <= r) {
            cnt++;
            ans += self(self, right, row - 1);
        }

        if (cnt == 2) {
            int mid = right - (row - 1);
            ans -= self(self, mid, row - 2);
        }

        return ans;
    };

    cout << fun(fun, n, L) << nl;
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