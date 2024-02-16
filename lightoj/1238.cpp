/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1238 - Power Puff Girls

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
    int hx = -1, hy = -1;
    vector<pair<int, int>> B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'm') {
                A[i][j] = '#';
            } else if (A[i][j] == 'h') {
                hx = i;
                hy = j;
            } else if (isalpha(A[i][j])) {
                B.push_back({i, j});
            }
        }
    }

    vector dist(n, vector<int>(m, inf));
    auto bfs = [&](int sx, int sy) -> void {
        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        dist[sx][sy] = 0;
        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '#') continue;
                if (dist[ux][uy] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[ux][uy] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    };

    bfs(hx, hy);
    int ans = 0;
    for (auto [x, y] : B) {
        ans = max(ans, dist[x][y]);
    }
    cout << ans << nl;
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