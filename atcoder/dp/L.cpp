/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Deque

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
    for (auto& x : A) cin >> x;

    vector dp(n, vector<ll>(n, -1));
    auto fun = [&](auto&& self, int l, int r) -> ll {
        if (l == r) return A[l];
        if (dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = max(A[l] - self(self, l + 1, r), A[r] - self(self, l, r - 1));
    };

    cout << fun(fun, 0, n - 1) << nl;
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