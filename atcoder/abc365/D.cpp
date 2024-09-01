/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AtCoder Janken 3

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
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            A[i] = 1;
        } else if (s[i] == 'R') {
            A[i] = 2;
        } else {
            A[i] = 3;
        }
    }

    // P = 1, R = 2, S = 3
    // 1 beats 2, 2 beats 3, 3 beats 1

    vector dp(n + 1, vector<int>(5, -1));
    auto fun = [&](auto&& self, int indx, int last) -> int {
        if (indx == n) return 0;
        auto& ans = dp[indx][last];
        if (ans != -1) return ans;

        ans = -inf;
        for (int i = 1; i <= 3; i++) {
            if (i != last && i != (A[indx] % 3) + 1) {
                ans = max(ans, (A[indx] == (i % 3) + 1) + self(self, indx + 1, i));
            }
        }
        return ans;
    };

    cout << fun(fun, 0, 0) << nl;
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