/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Ice Cave

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
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;

    if (a == c && b == d) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int x = a + dx[i];
            int y = b + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || A[x][y] == 'X') continue;
            cnt++;
        }
        cout << (cnt ? "YES" : "NO") << nl;
        return;
    }

    vector score(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            score[i][j] = (A[i][j] == 'X' ? 0 : 1);
        }
    }
    score[a][b] = 1;
    score[c][d] = (A[c][d] == 'X' ? 1 : 2);

    auto dfs = [&](auto&& self, int x, int y) -> void {
        if (x < 0 || x >= n || y < 0 || y >= m || score[x][y] == 0) return;
        score[x][y]--;
        for (int i = 0; i < 4; i++) {
            self(self, x + dx[i], y + dy[i]);
        }
    };

    dfs(dfs, a, b);

    cout << (score[c][d] == 0 ? "YES" : "NO") << nl;
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