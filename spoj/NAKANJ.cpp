/*  In the Name of ALLAH, the most gracious, the most merciful  */

// NAKANJ - Minimum Knight moves !!!

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {+2, +2, +1, +1, -1, -1, -2, -2};
vector<int> dy = {+1, -1, +2, -2, +2, -2, +1, -1};

void solve() {
    string a, b;
    cin >> a >> b;
    int ax = a.front() - 'a';
    int ay = a.back() - '1';
    int bx = b.front() - 'a';
    int by = b.back() - '1';

    int n = 8;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    auto bfs = [&](int x, int y) -> int {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        dist[x][y] = 0;

        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            if (dist[bx][by] != inf) return dist[bx][by];

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    };

    cout << bfs(ax, ay) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}