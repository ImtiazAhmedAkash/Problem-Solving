/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Illuminate Buildings

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    vector dp(n + 1, vector<int>(n + 1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if (A[i] == A[i - j]) {
                dp[i][j] = dp[i - j][j] + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans + 1 << nl;
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