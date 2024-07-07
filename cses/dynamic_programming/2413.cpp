/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Counting Towers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e6;

void solve() {
    vector dp(N + 1, vector<int>(2, 0));
    // dp[i][0] -> no. of ways to build towers such that the i-th row contains two vertical blocks
    // dp[i][1] -> no. of ways to build towers such that the i-th row contains a horizontal blocks
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (4LL * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (2LL * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << (0LL + dp[n][0] + dp[n][1]) % mod << nl;
    }
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