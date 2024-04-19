/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Knapsack 1

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
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    vector dp(n + 1, vector<ll>(k + 1));
    // dp[i][j] = maximum possible sum of values at index 'i' with a bag of weight 'j'
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][k] << nl;
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