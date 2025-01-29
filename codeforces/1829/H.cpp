/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Don't Blame Me

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector dp(n + 1, vector<int>(128, -1));
    auto fun = [&](auto&& self, int indx, int curAnd) -> ll {
        if (indx == n + 1) {
            return (__builtin_popcount(curAnd) == k ? 1 : 0);
        }
        auto& ans = dp[indx][curAnd];
        if (~ans) return ans;
        
        ll res = 0;
        res += self(self, indx + 1, curAnd);
        res += self(self, indx + 1, curAnd & A[indx]);
        if (res >= mod) res -= mod;
        
        return ans = res;
    };
    
    int ans = fun(fun, 1, (1 << 7) - 1);
    if (ans >= mod) ans -= mod;
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