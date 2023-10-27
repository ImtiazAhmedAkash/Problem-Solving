/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Guilty Prince

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void solve() {
    int r, c;
    cin >> c >> r;
    vector<string> A(r);
    vector vis(r, vector(c, false));
    pair<int, int> start = {-1, -1};
    for (int i = 0; i < r; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (A[i][j] == '@') {
                start = {i, j};
                break;
            }
        }
    }
    int ans = 1;
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (A[nr][nc] == '.' && !vis[nr][nc]) {
                q.push({nr, nc});
                vis[nr][nc] = true;
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
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}