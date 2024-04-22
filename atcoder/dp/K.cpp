/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Stones

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    vector dp(2, vector<int>(k + 1, -1));
    auto fun = [&](auto&& self, int player, int rem) -> int {
        if (rem == 0) return !player;
        if (rem < 0) return player;
        if (dp[player][rem] != -1) return dp[player][rem];

        int ans = 0;
        for (auto& x : A) {
            ans = self(self, !player, rem - x);
            if (ans == player) break;
        }
        return dp[player][rem] = ans;
    };

    cout << (fun(fun, 0, k) == 0 ? "First" : "Second") << nl;
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