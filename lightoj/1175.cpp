/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1175 - Jane and the Frost Giants

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
    vector A(n, vector<char>(m));
    int sx = -1, sy = -1;
    queue<pair<int, int>> F;
    vector fire(n, vector<int>(m, inf));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'J') {
                sx = i;
                sy = j;
            } else if (A[i][j] == 'F') {
                F.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    auto fire_bfs = [&]() -> void {
        while (!F.empty()) {
            auto [ux, uy] = F.front();
            F.pop();
            for (int i = 0; i < 4; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '#') continue;
                if (fire[ux][uy] + 1 < fire[nx][ny]) {
                    fire[nx][ny] = fire[ux][uy] + 1;
                    F.push({nx, ny});
                }
            }
        }
    };

    auto jane_bfs = [&](int sx, int sy) -> int {
        vector dist(n, vector<int>(m, inf));
        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        dist[sx][sy] = 0;
        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    return dist[ux][uy] + 1;
                }
                if (A[nx][ny] == '#' || fire[nx][ny] <= dist[ux][uy] + 1) continue;
                if (dist[ux][uy] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[ux][uy] + 1;
                    Q.push({nx, ny});
                }
            }
        }
        return -1;
    };

    fire_bfs();
    int ans = jane_bfs(sx, sy);
    if (ans == -1) {
        cout << "IMPOSSIBLE" << nl;
    } else {
        cout << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}