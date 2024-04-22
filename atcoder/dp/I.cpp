/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Coins

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
    vector<double> P(n);
    for (auto& x : P) cin >> x;
    
    vector dp(n, vector<double>(n, -1));
    auto fun = [&](auto&& self, int indx, int head) -> double {
        if (indx == n) {
            return (head > n - head) ? 1.0 : 0.0;
        }
        if (dp[indx][head] != -1) return dp[indx][head];
        return dp[indx][head] = P[indx] * self(self, indx + 1, head + 1) + (1.0 - P[indx]) * self(self, indx + 1, head);
    };
    
    cout << fixed << setprecision(12) << fun(fun, 0, 0) << nl;
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