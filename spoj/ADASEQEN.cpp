/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ADASEQEN - Ada and Subsequence

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
    int n, m;
    cin >> n >> m;
    vector<int> P(26);
    for (auto& x : P) {
        cin >> x;
    }
    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    auto fun = [&](auto&& self, int i, int j) -> int {
        if (i == n || j == m) return 0;
        auto& ans = dp[i][j];
        if (ans != -1) return ans;
        if (a[i] == b[j]) {
            ans = P[a[i] - 'a'] + self(self, i + 1, j + 1);
        } else {
            ans = max(self(self, i, j + 1), self(self, i + 1, j));
        }
        return ans;
    };

    cout << fun(fun, 0, 0) << nl;
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