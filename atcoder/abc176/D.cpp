/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Wizard in Maze

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {+0, -0, +1, -1};
vector<int> dy = {+1, -1, +0, -0};

void solve() {
    int h, w;
    cin >> h >> w;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    --sx, --sy, --tx, --ty;
    vector<string> A(h);
    for (auto &x : A) cin >> x;

    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && x < h && y >= 0 && y < w && A[x][y] != '#';
    };

    vector cost(h, vector<int>(w, inf));
    auto bfs = [&](int sx, int sy) -> void {
        deque<pair<int, int>> D;
        D.push_front({sx, sy});
        cost[sx][sy] = 0;
        while (!D.empty()) {
            auto [x, y] = D.front();
            D.pop_front();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (not valid(nx, ny)) continue;
                if (cost[nx][ny] > cost[x][y]) {
                    cost[nx][ny] = cost[x][y];
                    D.push_front({nx, ny});
                }
            }
            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (not valid(nx, ny)) continue;
                    if (cost[nx][ny] > cost[x][y] + 1) {
                        cost[nx][ny] = cost[x][y] + 1;
                        D.push_back({nx, ny});
                    }
                }
            }
        }
    };

    bfs(sx, sy);
    cout << (cost[tx][ty] == inf ? -1 : cost[tx][ty]) << nl;
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