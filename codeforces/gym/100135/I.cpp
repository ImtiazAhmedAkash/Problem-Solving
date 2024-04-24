/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Knapsack

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
    int s, n;
    cin >> s >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector dp(n, vector<int>(s + 1, -1));
    auto fun = [&](auto&& self, int indx, int rem) -> int {
        if (rem < 0) return -inf;
        if (indx == n) return 0;
        if (dp[indx][rem] != -1) return dp[indx][rem];
        return dp[indx][rem] = max(A[indx] + self(self, indx + 1, rem - A[indx]), self(self, indx + 1, rem));
    };

    cout << fun(fun, 0, s) << nl;
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