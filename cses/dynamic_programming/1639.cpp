/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Edit Distance

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

    vector dp(n + 1, vector<int>(m + 1, -1));
    //  dp[i][j] = minimum number of moves to make the first 'i' characters of string 's'
    //  equal to the first 'j' characters of string 't'.
    //  Here, the n and m represents the length, not the index.
    auto fun = [&](auto&& self, int n, int m) -> int {
        if (n == 0) return m;
        if (m == 0) return n;
        if (dp[n][m] != -1) return dp[n][m];
        if (s[n - 1] == t[m - 1]) {
            return dp[n][m] = self(self, n - 1, m - 1);
        } else {
            return dp[n][m] = 1 + min({self(self, n, m - 1), self(self, n - 1, m), self(self, n - 1, m - 1)});
        }
    };

    cout << fun(fun, n, m) << nl;
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