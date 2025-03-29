/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Add One

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

vector dp(10, vector<ll>(N + 5, -1));

void solve() {
    int n, m;
    cin >> n >> m;
    
    auto fun = [&](auto&& self, int digit, int rem) -> ll {
        if (rem == 0) return 1;
        auto &ans = dp[digit][rem];
        if (~ans) return ans;
        
        ans = 0;
        if (digit == 9) {
            ans = self(self, 1, rem - 1) + self(self, 0, rem - 1);
            if (ans >= mod) ans -= mod;
        }
        else {
            ans = self(self, digit + 1, rem - 1);
            if (ans >= mod) ans -= mod;
        }
        
        return ans;
    };
    
    ll ans = 0;
    while (n) {
        ans += fun(fun, n % 10, m);
        ans %= mod;
        n /= 10;
    }
    
    cout << ans << nl;
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