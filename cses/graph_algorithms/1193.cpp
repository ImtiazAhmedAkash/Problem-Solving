/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Labyrinth

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

    int ax = -1, ay = -1, bx = -1, by = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'A') {
                ax = i, ay = j;
            } else if (A[i][j] == 'B') {
                bx = i, by = j;
            }
        }
    }

    vector dist(n, vector<int>(m, inf));
    vector nxt(n, vector<pair<int, int>>(m));
    auto bfs = [&](int x, int y) -> void {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        dist[x][y] = 0;
        nxt[x][y] = {-1, -1};
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || A[nx][ny] == '#') continue;
                if (dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                    nxt[nx][ny] = {x, y};
                }
            }
        }
    };

    bfs(bx, by);

    if (dist[ax][ay] == inf) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        cout << dist[ax][ay] << nl;

        while (nxt[ax][ay] != make_pair(-1, -1)) {
            auto [x, y] = nxt[ax][ay];
            if (x < ax)
                cout << "U";
            else if (x > ax)
                cout << "D";
            else if (y < ay)
                cout << "L";
            else if (y > ay)
                cout << "R";
            tie(ax, ay) = nxt[ax][ay];
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