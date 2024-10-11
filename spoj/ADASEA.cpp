/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// ADASEA - Ada and Island

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

    int cnt = 0;
    vector<vector<bool>> used(n, vector<bool>(m, false));
    auto dfs = [&](auto&& self, int x, int y) -> void {
        if (x < 0 || x >= n || y < 0 || y >= m || used[x][y] || A[x][y] == '~') return;
        used[x][y] = true;
        cnt++;
        for (int i = 0; i < 4; i++) {
            self(self, x + dx[i], y + dy[i]);
        }
    };

    ll up = 0;
    ll down = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt = 0;
            dfs(dfs, i, j);
            up += 1LL * cnt * cnt;
        }
    }

    ll g = __gcd(up, down);
    up /= g;
    down /= g;
    if (up == 0 || down == 1) {
        cout << up << nl;
    } else {
        cout << up << " / " << down << nl;
    }
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