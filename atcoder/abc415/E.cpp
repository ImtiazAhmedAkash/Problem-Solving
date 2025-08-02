/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Hungry Takahashi

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 9e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int h, w;
    cin >> h >> w;
    vector A(h + 1, vector<ll>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> A[i][j];
        }
    }
    vector<ll> P(h + w);
    for (int i = 1; i < h + w; i++) {
        cin >> P[i];
    }
    
    
    vector dp(h + 5, vector<ll>(w + 5, INF));
    // dp[i][j] = minimum amount of extra coins needed from at cell (i, j) to reach (h, w)
    dp[h][w] = 0;
    for (int i = h; i >= 1; i--) {
        for (int j = w; j >= 1; j--) {
            if (i != h || j != w) dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] += P[i + j - 1] - A[i][j];
            dp[i][j] = max(0LL, dp[i][j]);
        }
    }
    
    cout << dp[1][1] << nl;
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