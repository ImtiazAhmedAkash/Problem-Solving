/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Marvolo Gaunt's Ring

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
const ll INF = 9e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> score(3);
    for (auto &x : score) cin >> x;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    vector dp(n + 1, vector<ll>(4, -INF));
    auto fun = [&](auto&& self, int indx, int current) -> ll {
        if (indx == n) {
            return (current == 3 ? 0 : -INF);
        }
        auto &ans = dp[indx][current];
        if (ans != -INF) return ans;
        
        ans = self(self, indx + 1, current);
        if (current < 3) ans = max(ans, 1LL * score[current] * A[indx] + self(self, indx, current + 1));
        
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