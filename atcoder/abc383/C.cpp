/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Humidifier 3

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
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    
    int ans = 0;
    vector dist(n, vector<int>(m, inf));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'H') {
                dist[i][j] = 0;
                q.push({i, j});
                ans++;
            }
        }
    }
    
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '#') continue;
            if (dist[x][y] + 1 < dist[nx][ny] && dist[x][y] + 1 <= d) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                ans++;
            }
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