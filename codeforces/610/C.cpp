/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Harmony Analysis

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
    int k;
    cin >> k;
    int n = 1 << k;

    // building Walsh Table -> elements are either +1 or -1, and the rows (or columns) are orthogonal to each other (their dot product is zero)
    auto fun = [&](auto&& self, int n) -> vector<vector<int>> {
        if (n == 1) {
            return {{1}};
        }

        vector<vector<int>> prev = self(self, n / 2);
        vector cur(n, vector<int>(n));
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                cur[i][j] = prev[i][j];
                cur[i + n / 2][j] = prev[i][j];
                cur[i][j + n / 2] = prev[i][j];
                cur[i + n / 2][j + n / 2] = -prev[i][j];
            }
        }
        return cur;
    };

    vector<vector<int>> ans = fun(fun, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (ans[i][j] == 1 ? '+' : '*');
        }
        cout << nl;
    }
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