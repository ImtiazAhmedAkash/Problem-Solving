/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tenzing and Balls

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // dp[i] = Maximum number of balls that can be removed till index 'i'.
    vector<int> dp(n + 1), Max(n + 1, -inf);
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], i + Max[A[i]]);
        Max[A[i]] = max(Max[A[i]], dp[i - 1] - (i - 1));
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