/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Jumping Takahashi

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
    int n, x;
    cin >> n >> x;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
    }

    vector dp(n, vector<int>(x + 1, -1));
    auto fun = [&](auto&& self, int indx, int sum) -> int {
        if (indx == n) return sum == 0 ? 1 : 0;
        if (sum < 0) return 0;
        if (dp[indx][sum] != -1) return dp[indx][sum];
        return dp[indx][sum] = max(self(self, indx + 1, sum - A[indx]), self(self, indx + 1, sum - B[indx]));
    };

    cout << (fun(fun, 0, x) ? "Yes" : "No") << nl;
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