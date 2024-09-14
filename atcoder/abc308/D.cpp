/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Snuke Maze

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
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    for (auto& x : A) cin >> x;
    string s = "snuke";

    vector dist(h, vector(w, inf));
    auto bfs = [&](int sx, int sy) {
        queue<pair<int, int>> Q;
        if (A[sx][sy] == 's') {
            Q.push({sx, sy});
        }
        dist[sx][sy] = 0;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            if (dist[h - 1][w - 1] != inf) return;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || A[nx][ny] != s[(dist[x][y] + 1) % 5]) continue;
                if (dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    };

    bfs(0, 0);
    cout << (dist[h - 1][w - 1] == inf ? "No" : "Yes") << nl;
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