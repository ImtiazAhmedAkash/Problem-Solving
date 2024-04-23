/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rabbit

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
    string s;
    cin >> s;

    vector<int> dp(n, -1);
    auto fun = [&](auto&& self, int indx) -> int {
        if (indx == 0) return 0;
        if (indx < 0 || s[indx] == 'w') return -inf;
        if (dp[indx] != -1) return dp[indx];

        int ans = -inf;
        for (auto x : {1, 3, 5}) {
            int tmp = 0;
            if (indx - x >= 0) {
                tmp = s[indx - x] == '"' ? 1 : 0;
            }
            ans = max(ans, tmp + self(self, indx - x));
        }
        return dp[indx] = ans;
    };

    int ans = fun(fun, n - 1);
    cout << (ans < 0 ? -1 : ans) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}