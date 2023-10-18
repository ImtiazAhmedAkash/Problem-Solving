/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Knight Moves

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
int dir[] = {-1, +2, -1, -2, +1, +2, +1, -2, -1};

void solve() {
    string a, b;
    while (cin >> a >> b) {
        vector<vector<int>> Chess(8, vector<int>(8, -1));

        auto bfs = [&](int sx, int sy) {
            Chess[sx][sy] = 0;
            queue<pair<int, int>> Q;
            Q.push({sx, sy});
            while (!Q.empty()) {
                int ux = Q.front().first;
                int uy = Q.front().second;
                Q.pop();
                for (int i = 0; i < 8; i++) {
                    int vx = ux + dir[i];
                    int vy = uy + dir[i + 1];
                    if (vx < 0 || vy < 0 || vx >= 8 || vy >= 8) continue;
                    if (Chess[vx][vy] == -1) {
                        Chess[vx][vy] = Chess[ux][uy] + 1;
                        Q.push({vx, vy});
                    }
                }
            }
        };

        bfs(a[0] - 'a', a[1] - '0' - 1);
        int ans = Chess[b[0] - 'a'][b[1] - '0' - 1];
        cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves." << nl;
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