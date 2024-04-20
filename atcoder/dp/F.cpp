/*  In the Name of ALLAH, the most gracious, the most merciful  */

// LCS

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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector dp(n + 1, vector<int>(m + 1));
    // dp[i][j] = length of the LCS using the first 'i' characters of 's' and first 'j' characters of 't'
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--, j--;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            j--;
        } else {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
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