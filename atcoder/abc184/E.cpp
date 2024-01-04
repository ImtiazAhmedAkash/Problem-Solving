/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Third Avenue

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
    int h, w;
    cin >> h >> w;
    vector A(h, vector<char>(w));
    vector<vector<pair<int, int>>> V(26);
    int sx = -1, sy = -1, fx = -1, fy = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (A[i][j] == 'G') {
                fx = i;
                fy = j;
            }
            if (islower(A[i][j])) {
                V[A[i][j] - 'a'].push_back({i, j});
            }
        }
    }

    vector<int> dir = {1, 0, -1, 0, 1};
    vector dist(h, vector<int>(w, inf));

    auto isValid = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < h && y < w && A[x][y] != '#';
    };

    auto bfs = [&](int sx, int sy) {
        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        dist[sx][sy] = 0;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            if (islower(A[x][y])) {
                for (auto [nx, ny] : V[A[x][y] - 'a']) {
                    if (dist[x][y] + 1 < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + 1;
                        Q.push({nx, ny});
                    }
                }
                V[A[x][y] - 'a'].clear();
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if (isValid(nx, ny) && dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    };

    bfs(sx, sy);
    cout << (dist[fx][fy] == inf ? -1 : dist[fx][fy]) << nl;
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