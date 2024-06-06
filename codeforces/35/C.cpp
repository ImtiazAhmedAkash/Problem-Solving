/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fire Again

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
    vector dist(n, vector<int>(m, inf));
    int time = 0;
    int ax = 0, ay = 0;

    queue<pair<int, int>> Q;
    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        dist[x][y] = 0;
        Q.push({x, y});
    }

    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[x][y] + 1 < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                Q.push({nx, ny});
                if (time < dist[nx][ny]) {
                    time = dist[nx][ny];
                    ax = nx, ay = ny;
                }
            }
        }
    }

    cout << ax + 1 << " " << ay + 1 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}