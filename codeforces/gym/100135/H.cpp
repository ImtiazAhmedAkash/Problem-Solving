/*  In the Name of ALLAH, the most gracious, the most merciful  */

//  Peaceful Sets

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
    
    vector dp(n + 1, vector<ll>(n + 1, -1));
    auto fun = [&](auto&& self, int last, int rem) -> ll {
        if (rem == 0) return 1;
        if (rem < last) return 0;
        if (dp[last][rem] != -1) return dp[last][rem];
        ll ans = 0;
        for (int i = 2 * last; i <= rem; i++) {
            ans += self(self, i, rem - i);
        }
        return dp[last][rem] = ans;
    };
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += fun(fun, i, n - i);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("peacefulsets.in", "r", stdin);
    freopen("peacefulsets.out", "w", stdout);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}