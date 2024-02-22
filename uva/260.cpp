/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 260 - Il Gioco dell'X

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {-1, -1, +0, +0, +1, +1};
vector<int> dy = {-1, +0, -1, +1, +0, +1};

void solve() {
    int t = 1;
    int n;
    while (cin >> n && n) {
        vector<string> G(n);
        for (auto& x : G) cin >> x;
        vector<vector<bool>> used(n, vector<bool>(n, false));

        auto bfs = [&](int x, int y) -> bool {
            queue<pair<int, int>> Q;
            Q.push({x, y});
            used[x][y] = true;
            while (!Q.empty()) {
                auto[ux, uy] = Q.front();
                Q.pop();
                if (uy + 1 == n) return true;
                for (int i = 0; i < 6; i++) {
                    int nx = ux + dx[i];
                    int ny = uy + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || G[nx][ny] == 'b') continue;
                    if (!used[nx][ny]) {
                        used[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
            return false;
        };
        
        bool white = false;
        for (int i = 0; i < n; i++) {
            if (!used[i][0]) {
                white |= bfs(i, 0);
            }
        }
        cout << t++ << " " << (white ? "W" : "B") << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}