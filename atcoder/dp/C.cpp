/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vacation

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
    vector day(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> day[i][j];
        }
    }

    vector dp(n, vector<int>(3, 0));
    // dp[i][j] = maximum possible happiness points on day 'i' if 'j'-th task is performed
    // j = 0 -> task A, j = 1 -> task B, j = 2 -> task C
    for (int i = 0; i < 3; i++) {
        dp[0][i] = day[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = day[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[n - 1][i]);
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