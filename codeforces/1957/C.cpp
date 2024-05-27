/*  In the Name of ALLAH, the most gracious, the most merciful  */

// How Does the Rook Move?

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
    int n, k;
    cin >> n >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            n--;
        } else {
            n -= 2;
        }
    }

    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + (1LL * (i - 1) * 2 * dp[i - 2]) % mod) % mod;
    }
    cout << dp[n] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}