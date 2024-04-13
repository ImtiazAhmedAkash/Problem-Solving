/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Removing Digits

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

    vector<int> dp(n + 1, -1);
    auto fun = [&](auto&& self, int x) -> int {
        if (x == 0) return 0;
        if (dp[x] != -1) return dp[x];
        int ans = inf;
        string s = to_string(x);
        for (auto c : s) {
            if (c == '0') continue;
            ans = min(ans, 1 + self(self, x - (c - '0')));
        }
        return dp[x] = ans;
    };

    cout << fun(fun, n) << nl;
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