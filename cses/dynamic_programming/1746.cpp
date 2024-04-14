/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Array Description

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
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector dp(n, vector<int>(m + 1));

    if (A[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][A[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (A[i] != 0) {
            int Prev = (A[i] - 1 > 0 ? dp[i - 1][A[i] - 1] : 0);
            int Next = (A[i] + 1 <= m ? dp[i - 1][A[i] + 1] : 0);
            dp[i][A[i]] = (0LL + Prev + dp[i - 1][A[i]] + Next) % mod;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            int Prev = (j - 1 > 0 ? dp[i - 1][j - 1] : 0);
            int Next = (j + 1 <= m ? dp[i - 1][j + 1] : 0);
            dp[i][j] = (0LL + Prev + dp[i - 1][j] + Next) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n - 1][i]) % mod;
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