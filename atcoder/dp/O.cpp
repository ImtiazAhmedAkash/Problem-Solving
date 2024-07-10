/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Matching

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector dp(n, vector<int>(1 << n, -1));
    // dp[i][mask] -> no. of ways to make pairs from i-th male to (n - 1)-th with the available women (given as mask)

    auto fun = [&](auto&& self, int indx, int mask) -> int {
        if (indx == n) {
            return (mask == 0 ? 1 : 0);
        }
        auto& ans = dp[indx][mask];
        if (ans != -1) return ans;

        ans = 0;
        for (int bit = 0; bit < n; bit++) {
            if ((mask & (1 << bit)) && A[indx][bit]) {
                ans = (0LL + ans + self(self, indx + 1, mask ^ (1 << bit))) % mod;
            }
        }
        return ans;
    };

    cout << fun(fun, 0, (1 << n) - 1) << nl;
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