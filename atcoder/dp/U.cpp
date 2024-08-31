/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Grouping

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
    vector A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<ll> score(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = i + 1; j < n; j++) {
                if (mask & (1 << j)) {
                    score[mask] += A[i][j];
                }
            }
        }
    }

    vector<ll> dp(1 << n, -1);
    auto fun = [&](auto&& self, int mask) -> ll {
        if (mask == 0) return 0;
        if (dp[mask] != -1) return dp[mask];
        ll ans = 0;
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            ans = max(ans, score[sub] + self(self, mask ^ sub));
        }
        return dp[mask] = ans;
    };

    cout << fun(fun, (1 << n) - 1) << nl;
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