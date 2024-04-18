/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Sets II

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
    int mx_sum = n * (n + 1) / 2;
    if (mx_sum & 1) {
        cout << 0 << nl;
        return;
    }

    int target_sum = mx_sum / 2;

    vector dp(n, vector<int>(target_sum + 1, -1));
    auto fun = [&](auto&& self, int indx, int sum) -> int {
        if (sum == 0) return 1;
        if (sum < 0 || indx == n) return 0;
        if (dp[indx][sum] != -1) return dp[indx][sum];
        return dp[indx][sum] = (0LL + self(self, indx + 1, sum - indx) + self(self, indx + 1, sum)) % mod;
    };

    cout << fun(fun, 1, target_sum) << nl;
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