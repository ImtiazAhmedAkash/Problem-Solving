/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Coin Combinations I

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
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (auto& z : A) cin >> z;
    
    vector<int> dp(x + 1, -1);
    auto fun = [&](auto&& self, int x) -> int {
        if (x == 0) return 1;
        if (x < 0) return 0;
        if (dp[x] != -1) return dp[x];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ((ll)ans + self(self, x - A[i])) % mod;
        }
        return dp[x] = ans;
    };
    
    cout << fun(fun, x) << nl;
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