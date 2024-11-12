/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Letter

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
    string s;
    cin >> s;

    int n = s.size();
    vector dp(n, vector<int>(3, -1));
    // last = 1 means capital letter
    // last = 2 means small letter
    auto fun = [&](auto&& self, int indx, int last) -> int {
        if (indx == n) return 0;
        auto& ans = dp[indx][last];
        if (~ans) return ans;

        ans = inf;
        if (last != 2) {
            ans = min(ans, (isupper(s[indx]) ? 0 : 1) + self(self, indx + 1, 1));
            ans = min(ans, (islower(s[indx]) ? 0 : 1) + self(self, indx + 1, 2));
        } else {
            ans = min(ans, (islower(s[indx]) ? 0 : 1) + self(self, indx + 1, 2));
        }

        return ans;
    };

    int ans = fun(fun, 0, 0);
    cout << ans << nl;
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