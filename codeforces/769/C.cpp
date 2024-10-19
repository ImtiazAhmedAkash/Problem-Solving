/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Cycle In Maze

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// D -> L -> R -> U  direction
vector<int> dx = {+1, +0, +0, -1};
vector<int> dy = {+0, -1, +1, +0};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> A(n);
    for (auto &x : A) cin >> x;

    if (k & 1) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'X') {
                x = i, y = j;
            }
        }
    }

    vector dist(n, vector<int>(m, inf));
    dist[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '*') continue;
            if (dist[ux][uy] + 1 < dist[nx][ny]) {
                dist[nx][ny] = dist[ux][uy] + 1;
                q.push({nx, ny});
            }
        }
    }

    string dir = "DLRU";
    int ux = x, uy = y;
    string ans;
    int moves = k;
    while (k--) {
        for (int i = 0; i < 4; i++) {
            int nx = ux + dx[i];
            int ny = uy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (A[nx][ny] != '*' && dist[nx][ny] <= k) {
                ux = nx, uy = ny;
                ans += dir[i];
                break;
            }
        }
    }

    cout << (ans.size() == moves ? ans : "IMPOSSIBLE") << nl;
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