/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Frog 1

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

    vector<int> dp(n, -1);
    auto fun = [&](auto&& self, int indx) -> int {
        if (indx == n - 1) return 0;
        if (dp[indx] != -1) return dp[indx];
        int ans = inf;
        if (indx + 1 < n) {
            ans = min(ans, abs(A[indx] - A[indx + 1]) + self(self, indx + 1));
        }
        if (indx + 2 < n) {
            ans = min(ans, abs(A[indx] - A[indx + 2]) + self(self, indx + 2));
        }
        return dp[indx] = ans;
    };

    cout << fun(fun, 0) << nl;
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