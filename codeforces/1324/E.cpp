/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sleeping Schedule

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
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    vector dp(n + 1, vector<int>(h + 1, -1));
    auto fun = [&](auto&& self, int indx, int last) -> int {
        if (indx == n) return 0;
        auto& ans = dp[indx][last];
        if (~ans) return ans;
        
        ans = 0;
        int cur = (last + A[indx]) % h;
        int prev = (cur - 1 + h) % h;
        
        ans = max(ans, (l <= prev && prev <= r ? 1 : 0) + self(self, indx + 1, prev));
        ans = max(ans, (l <= cur && cur <= r ? 1 : 0) + self(self, indx + 1, cur));
        
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