/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// C - Snake Numbers

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
    ll l, r;
    cin >> l >> r;

    string s;
    int n;

    vector dp(20, vector (15, vector<ll>(2, -1)));
    auto fun = [&](auto&& self, int indx, int firstDigit, int is_smaller) -> ll {
        if (indx == n) {
            return (firstDigit == 10 ? 0 : 1);
        }
        auto& ans = dp[indx][firstDigit][is_smaller];
        if (~ans) return ans;
        
        ans = 0;
        if (is_smaller) {
            int digit = firstDigit - 1;
            for (int i = 0; i <= digit; i++) {
                if (firstDigit == 10) {
                    if (i == 0) ans += self(self, indx + 1, 10, 1);
                    else ans += self(self, indx + 1, i, 1);
                }
                else {
                    ans += self(self, indx + 1, firstDigit, 1);
                }
            }
        }
        else {
            int digit = min(firstDigit - 1, s[indx] - '0');
            for (int i = 0; i <= digit; i++) {
                if (firstDigit == 10) { // number has not started yet
                    if (i == 0) ans += self(self, indx + 1, 10, 1);
                    else {
                        if (i == s[indx] - '0') ans += self(self, indx + 1, i, 0);
                        else {
                            ans += self(self, indx + 1, i, 1);
                        }
                    }
                }
                else { // number has started
                    if (i == s[indx] - '0') ans += self(self, indx + 1, firstDigit, 0);
                    else ans += self(self, indx + 1, firstDigit, 1);
                }
            }
        }
        
        return ans;
    };

    s = to_string(r);
    n = s.size();
    ll ans1 = fun(fun, 0, 10, 0);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    s = to_string(l - 1);
    n = s.size();
    ll ans2 = fun(fun, 0, 10, 0);

    cout << ans1 - ans2 << nl;
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