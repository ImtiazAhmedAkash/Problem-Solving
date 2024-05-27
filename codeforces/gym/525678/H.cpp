/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Save Stella!!

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
    vector G(n, vector<char>(m));

    vector bomb(n, vector<int>(m, inf));
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == '0') {
                Q.push({i, j});
                bomb[i][j] = 0;
            }
        }
    }

    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (bomb[x][y] + 1 < bomb[nx][ny]) {
                bomb[nx][ny] = bomb[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }

    int a, b;
    cin >> a >> b;
    --a, --b;
    vector dist(n, vector<int>(m, inf));
    if (bomb[a][b] != 0) {
        Q.push({a, b});
        dist[a][b] = 0;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist[x][y] + 1 < dist[nx][ny] && dist[x][y] + 1 < bomb[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    if (dist[n - 1][m - 1] == inf) {
        cout << "Impossible" << nl;
    } else {
        cout << dist[n - 1][m - 1] << nl;
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