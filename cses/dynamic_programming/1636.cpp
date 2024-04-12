/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Coin Combinations II

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

    vector dp(n, vector<int>(x + 1));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= x; j++) {
            if (j - A[i] >= 0) {
                dp[i][j] = dp[i][j - A[i]];
            }
            if (i + 1 < n) {
                dp[i][j] = ((ll)dp[i][j] + dp[i + 1][j]) % mod;
            }
        }
    }

    cout << dp[0][x] << nl;
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