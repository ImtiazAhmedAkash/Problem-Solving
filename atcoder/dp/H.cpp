/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Grid 1

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
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    vector dp(n, vector<int>(m));
    //  dp[i][j] = number of ways to reach cell (i, j) from cell (0, 0). (0-based indexing)
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '#' || i + j == 0) continue;
            int up = (i - 1 >= 0 ? dp[i - 1][j] : 0);
            int left = (j - 1 >= 0 ? dp[i][j - 1] : 0);
            dp[i][j] = (0LL + up + left) % mod;
        }
    }
    cout << dp[n - 1][m - 1] << nl;
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