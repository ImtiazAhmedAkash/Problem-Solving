/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Knapsack 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9 + 5;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    int m = n * 1000;
    vector dp(n + 1, vector<int>(m + 1));
    //  dp[i][j] = minimum weight to form a value of 'j' using first 'i' elements
    for (int i = 1; i <= m; i++) {
        dp[0][i] = inf;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (dp[n][i] <= k) {
            ans = max(ans, i);
        }
    }
    cout << ans << nl;
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