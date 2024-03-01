/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Takahashi Gets Lost

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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    auto good = [&](int row, int col) -> bool {
        for (auto c : s) {
            if (c == 'U') {
                row--;
            } else if (c == 'D') {
                row++;
            } else if (c == 'L') {
                col--;
            } else {
                col++;
            }
            if (A[row][col] == '#') return false;
        }
        return true;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.' && good(i, j)) {
                ans++;
            }
        }
    }
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