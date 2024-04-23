/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Basketball Exercise

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
    vector A(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (auto& x : A[i]) {
            cin >> x;
        }
    }

    vector dp(2, vector<ll>(n, -1));
    auto fun = [&](auto&& self, int row, int indx) -> ll {
        if (indx >= n) return 0;
        if (dp[row][indx] != -1) return dp[row][indx];
        return dp[row][indx] = A[row][indx] + max(self(self, !row, indx + 1), self(self, !row, indx + 2));
    };

    cout << max(fun(fun, 0, 0), fun(fun, 1, 0)) << nl;
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