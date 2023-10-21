/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sensors

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
vector<int> dir = {0, +1, -1, 0, -1, -1, +1, +1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector used(n, vector(m, false));
    
    auto bfs = [&](int x, int y) {
        used[x][y] = true;
        queue<pair<int, int>> Q;
        Q.push({x, y});
        while (!Q.empty()) {
            auto [ax, ay] = Q.front();
            Q.pop();
            for (int i = 0; i + 1 < dir.size(); i++) {
                int nx = ax + dir[i];
                int ny = ay + dir[i + 1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || A[nx][ny] == '.') continue;
                if (!used[nx][ny]) {
                    Q.push({nx, ny});
                    used[nx][ny] = true;
                }
            }
        }
    };
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.' || used[i][j]) continue;
            bfs(i, j);
            ans++;
        }
    }
    cout << ans << nl;
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