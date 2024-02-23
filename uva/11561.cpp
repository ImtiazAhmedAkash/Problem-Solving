/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11561 - Getting Gold

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
    while (cin >> m >> n) {
        vector<vector<char>> A(n, vector<char>(m));
        int sx = -1, sy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
                if (A[i][j] == 'P') {
                    sx = i, sy = j;
                }
            }
        }

        auto bfs = [&](int x, int y) -> int {
            int cnt = 0;
            vector<vector<bool>> used(n, vector<bool>(m, false));
            queue<pair<int, int>> Q;
            Q.push({x, y});
            used[x][y] = true;
            while (!Q.empty()) {
                auto [ux, uy] = Q.front();
                Q.pop();
                if (A[ux][uy] == 'G') cnt++;

                bool trap = false;
                for (int i = 0; i < 4; i++) {
                    int nx = ux + dx[i];
                    int ny = uy + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (A[nx][ny] == 'T') {
                        trap = true;
                        break;
                    }
                }
                if (trap) continue;

                for (int i = 0; i < 4; i++) {
                    int nx = ux + dx[i];
                    int ny = uy + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '#') continue;
                    if (!used[nx][ny]) {
                        used[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
            return cnt;
        };

        cout << bfs(sx, sy) << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}