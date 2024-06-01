/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Monsters

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

    vector time(n, vector<int>(m, inf));
    queue<pair<int, int>> Q;
    int ax = -1, ay = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'A') {
                ax = i, ay = j;
            } else if (A[i][j] == 'M') {
                Q.push({i, j});
                time[i][j] = 0;
            }
        }
    }

    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || A[nx][ny] == '#') continue;
            if (time[x][y] + 1 < time[nx][ny]) {
                time[nx][ny] = time[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }

    vector dist(n, vector<int>(m, inf));
    vector par(n, vector<pair<int, int>>(m));
    auto bfs = [&](int x, int y) -> pair<int, int> {
        assert(Q.empty());
        Q.push({x, y});
        dist[x][y] = 0;
        par[x][y] = {-1, -1};

        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            if (x == 0 || y == 0 || x + 1 == n || y + 1 == m) {
                return {x, y};
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || A[nx][ny] == '#') continue;
                if (dist[x][y] + 1 < dist[nx][ny] && dist[x][y] + 1 < time[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    par[nx][ny] = {x, y};
                    Q.push({nx, ny});
                }
            }
        }

        return {-1, -1};
    };

    auto P = bfs(ax, ay);

    if (P == make_pair(-1, -1)) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        auto [x, y] = P;
        cout << dist[x][y] << nl;

        string ans = "";
        while (par[x][y] != make_pair(-1, -1)) {
            auto [px, py] = par[x][y];
            if (px < x)
                ans += 'D';
            else if (px > x)
                ans += 'U';
            else if (py < y)
                ans += 'R';
            else if (py > y)
                ans += 'L';
            tie(x, y) = par[x][y];
        }
        cout << string(ans.rbegin(), ans.rend()) << nl;
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