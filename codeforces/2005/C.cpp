/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Lazy Narek

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
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;
        s += k;
    }

    string t = "narek";

    vector dp(n * m + 1, vector<int>(5, -inf));
    auto fun = [&](auto&& self, int indx, int need) -> int {
        if (indx >= n * m) return -need;
        auto& ans = dp[indx][need];
        if (ans != -inf) return ans;

        if (indx % m == 0) {
            ans = max(ans, self(self, indx + m, need));
        }
        if (s[indx] == t[need]) {
            if (need + 1 == 5) {
                ans = max(ans, 5 + self(self, indx + 1, 0));
            } else {
                ans = max(ans, self(self, indx + 1, need + 1));
            }
        } else if (t.find(s[indx]) != -1) {
            ans = max(ans, self(self, indx + 1, need) - 1);
        } else {
            ans = max(ans, self(self, indx + 1, need));
        }

        return ans;
    };

    cout << fun(fun, 0, 0) << nl;
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