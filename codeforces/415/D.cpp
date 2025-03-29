/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Mashmokh and ACM

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
const int mod = 1000000007;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector dp(n + 5, vector<ll>(k + 5, -1));
    auto fun = [&](auto&& self, int last, int rem) -> ll {
        if (rem == 0) return 1;
        auto &ans = dp[last][rem];
        if (~ans) return ans;
        
        ans = 0;
        for (int i = 1; last * i <= n; i++) {
            ans += self(self, last * i, rem - 1);
            if (ans >= mod) ans -= mod;
        }
        
        return ans;
    };
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += fun(fun, i, k - 1);
        if (ans >= mod) ans -= mod;
    }
    
    cout << ans << nl;
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