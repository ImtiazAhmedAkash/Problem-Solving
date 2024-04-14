/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Book Shop

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
    int n, x;
    cin >> n >> x;
    vector<int> cost(n), page(n);
    for (auto& z : cost) cin >> z;
    for (auto& z : page) cin >> z;

    vector dp(n, vector<int>(x + 1));
    // dp[i][j] represents the maximum amount of pages upto index i that costs at most j
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            int take = 0;
            if (cost[i] <= j) {
                take = page[i];
                if (i - 1 >= 0) {
                    take += dp[i - 1][j - cost[i]];
                }
            }
            int skip = (i - 1 >= 0 ? dp[i - 1][j] : 0);
            dp[i][j] = max(skip, take);
        }
    }
    cout << dp[n - 1][x] << nl;
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