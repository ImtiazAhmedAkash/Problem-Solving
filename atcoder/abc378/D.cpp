/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Count Simple Paths

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {-1, +0, +1, +0};
vector<int> dy = {+0, +1, +0, -1};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> A(n);
    for (auto &x : A) cin >> x;

    vector used(n, vector<bool>(m, false));

    auto fun = [&](auto&& self, int x, int y, int r) -> ll {
        if (r == 0) return 1;

        used[x][y] = true;
        ll ans = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || used[nx][ny] || A[nx][ny] == '#') continue;
            ans += self(self, nx, ny, r - 1);
        }
        used[x][y] = false;

        return ans;
    };

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.') {
                ans += fun(fun, i, j, k);
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