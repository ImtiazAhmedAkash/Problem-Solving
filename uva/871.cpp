/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 871 - Counting Cells in a Blob

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {-1, +0, +1, +0, -1, -1, +1, +1};
vector<int> dy = {+0, +1, +0, -1, -1, +1, -1, +1};

void solve() {
    vector<string> A;
    string s;
    while (getline(cin, s) && !s.empty()) {
        A.push_back(s);
    }
    int n = A.size();
    int m = A[0].size();

    vector<vector<bool>> used(n, vector<bool>(m, false));
    auto bfs = [&](int x, int y) -> int {
        int cnt = 0;
        queue<pair<int, int>> Q;
        Q.push({x, y});
        used[x][y] = true;
        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            cnt++;
            for (int i = 0; i < 8; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '0') continue;
                if (!used[nx][ny]) {
                    used[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
        return cnt;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '1' && !used[i][j]) {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);
    int T = stoi(s);
    cin.ignore();
    for (int t = 1; t <= T; t++) {
        solve();
        if (t < T) cout << nl;
    }

    return 0;
}