/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bombs! NO they are Mines!! 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
int dir[] = {1, 0, -1, 0, 1};

void solve() {
    int r, c;
    while (cin >> r >> c && (r && c)) {
        vector<vector<int>> Grid(r, vector<int>(c, -1));
        int n;
        cin >> n;
        while (n--) {
            int row, mine;
            cin >> row >> mine;
            while (mine--) {
                int col;
                cin >> col;
                Grid[row][col] = inf;
            }
        }

        auto bfs = [&](int sx, int sy) {
            queue<pair<int, int>> Q;
            Q.push({sx, sy});
            Grid[sx][sy] = 0;
            while (!Q.empty()) {
                int ax = Q.front().first;
                int ay = Q.front().second;
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = ax + dir[i], ny = ay + dir[i + 1];
                    if (nx < 0 || ny < 0 || nx >= r || ny >= c || Grid[nx][ny] == inf) continue;
                    if (Grid[nx][ny] == -1) {
                        Q.push({nx, ny});
                        Grid[nx][ny] = Grid[ax][ay] + 1;
                    }
                }
            }
        };

        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        bfs(sx, sy);
        cout << Grid[tx][ty] << nl;
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