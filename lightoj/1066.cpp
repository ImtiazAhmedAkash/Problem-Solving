/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1066 - Gathering Food

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
    int n;
    cin >> n;
    vector A(n, vector<char>(n));
    int k = 0;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if (isalpha(A[i][j])) k++;
        }
    }

    auto bfs = [&](int sx, int sy) -> int {
        vector dist(n, vector<int>(n, inf));
        vector inBFS(n, vector<bool>(n, false));

        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        dist[sx][sy] = 0;
        inBFS[sx][sy] = true;
        int cnt = 0;

        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();

            if (A[ux][uy] == (char)('A' + cnt)) {
                cnt++;
                if (cnt == k) return dist[ux][uy];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == ux && j == uy) continue;
                        inBFS[i][j] = false;
                    }
                }
                while (!Q.empty()) Q.pop();
            }

            for (int i = 0; i < 4; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || A[nx][ny] == '#') continue;
                if (isalpha(A[nx][ny]) && A[nx][ny] > (char)('A' + cnt)) continue;

                if (!inBFS[nx][ny]) {
                    inBFS[nx][ny] = true;
                    dist[nx][ny] = dist[ux][uy] + 1;
                    Q.push({nx, ny});
                }
            }
        }

        return -1;
    };

    int ans = bfs(sx, sy);
    if (ans == -1) {
        cout << "Impossible" << nl;
    } else {
        cout << ans << nl;
    }
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