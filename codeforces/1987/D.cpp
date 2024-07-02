/*  In the Name of ALLAH, the most gracious, the most merciful  */

// World is Mine

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
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    n = cnt.size();
    vector<int> A;
    for (auto [x, y] : cnt) {
        A.push_back(y);
    }

    // dp[i][j] -> maximum types of cakes bob can eat
    vector dp(n + 1, vector<int>(n + 1, -1));
    auto fun = [&](auto&& self, int indx, int rem) -> int {
        if (indx == n) return 0;
        if (dp[indx][rem] != -1) return dp[indx][rem];
        int ans = self(self, indx + 1, rem + 1);
        if (A[indx] <= rem) {
            ans = max(ans, 1 + self(self, indx + 1, rem - A[indx]));
        }
        return dp[indx][rem] = ans;
    };

    cout << n - fun(fun, 0, 0) << nl;
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