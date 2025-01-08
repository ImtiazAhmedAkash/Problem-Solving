/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Snaky Walk

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
    for (auto &x : A) cin >> x;

    int sx = -1, sy = -1;
    int gx = -1, gy = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (A[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (A[i][j] == 'G') {
                gx = i, gy = j;
            }
        }
    }

    auto bfs = [&](int x, int y, int last) -> int {
        vector dist(h + 1, vector<int>(w + 1, inf));
        dist[x][y] = 0;
        queue<array<int, 3>> q;
        q.push({x, y, last});

        while (!q.empty()) {
            auto [ux, uy, last] = q.front();
            q.pop();

            for (int i : {-1, 1}) {
                int nx = ux;
                int ny = uy;
                
                if (last == 0) {
                    nx = ux + i;
                } else {
                    ny = uy + i;
                }
                
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || A[nx][ny] == '#') continue;
                if (dist[ux][uy] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[ux][uy] + 1;
                    q.push({nx, ny, 1 - last});
                }
            }
        }
        
        return dist[gx][gy];
    };

    int ans = min(bfs(sx, sy, 0), bfs(sx, sy, 1));
    
    cout << (ans == inf ? -1 : ans) << nl;
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