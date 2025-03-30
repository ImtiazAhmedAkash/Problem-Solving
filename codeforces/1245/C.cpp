/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Constanze's Machine

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
const int N = 100;

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0 << nl;
            return;
        }
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
    auto fun = [&](auto&& self, int indx, int type) -> ll {
        if (indx == n) return 1;
        auto &ans = dp[indx][type];
        if (~ans) return ans;
        
        ans = 0;
        ans = self(self, indx + 1, 0);
        if (ans >= mod) ans -= mod;
        if (indx + 1 < n && s[indx] == s[indx + 1] && (s[indx] == 'u' || s[indx] == 'n')) {
            ans += self(self, indx + 2, 1);
            if (ans >= mod) ans -= mod;
        }
        
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