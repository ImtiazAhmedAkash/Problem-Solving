/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1337 - The Crystal Maze

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
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    vector parent(n, vector<pair<int, int>>(m, {-1, -1}));
    auto bfs = [&](int sx, int sy) -> int {
        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        parent[sx][sy] = {sx, sy};
        int cnt = 0;
        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            if (A[ux][uy] == 'C') cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '#') continue;
                if (parent[nx][ny] == make_pair(-1, -1)) {
                    parent[nx][ny] = {sx, sy};
                    Q.push({nx, ny});
                }
            }
        }
        return cnt;
    };

    vector ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (parent[i][j] == make_pair(-1, -1)) {
                ans[i][j] = bfs(i, j);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        auto [x, y] = parent[a][b];
        cout << ans[x][y] << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": " << nl;
        solve();
    }

    return 0;
}