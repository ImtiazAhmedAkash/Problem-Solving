/*  In the Name of ALLAH, the most gracious, the most merciful  */

// MOVIFAN - Movie Fan

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1000000007;
const int N = 2e5 + 5;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector<int> dp(n, -1);
    auto fun = [&](auto&& self, int indx) -> int {
        if (indx == n) return 1;
        if (dp[indx] != -1) return dp[indx];
        int skip = self(self, indx + 1);
        int take = self(self, lower_bound(A.begin(), A.end(), A[indx] + l) - A.begin());
        return dp[indx] = (0LL + skip + take) % mod;
    };

    cout << fun(fun, 0) - 1 << nl;
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