/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Kevin and Puzzle

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<int> dp(n + 5, -1);
    auto fun = [&](auto&& self, int indx) -> int {
        if (indx >= n + 1) return 1;
        if (dp[indx] != -1) return dp[indx];
        
        ll ans = 0;
        if (indx + 1 == n + 1 || (indx + 1 <= n && A[indx] == A[indx + 1])) {
            ans += self(self, indx + 1);
        }
        if (indx + 2 == n + 1 || (indx + 2 <= n && A[indx] + 1 == A[indx + 2])) {
            ans += self(self, indx + 2);
        }
        
        if (ans >= mod) ans -= mod;
        return dp[indx] = ans;
    };
    
    cout << fun(fun, 0) << nl;
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