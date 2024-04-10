/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dice Combinations

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
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, -1);
    auto fun = [&](auto&& self, int n) -> int {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            ans = ((ll) ans + self(self, n - i)) % mod;
        }
        return dp[n] = ans;
    };
    
    cout << fun(fun, n) << nl;
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