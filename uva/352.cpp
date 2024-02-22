/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 352 - The Seasonal War

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
    int T = 1;
    int n;
    while (cin >> n) {
        vector<string> A(n);
        for (auto& x : A) cin >> x;

        vector<vector<bool>> used(n, vector<bool>(n, false));
        auto bfs = [&](int x, int y) -> void {
            queue<pair<int, int>> Q;
            Q.push({x, y});
            used[x][y] = true;
            while (!Q.empty()) {
                auto [ux, uy] = Q.front();
                Q.pop();
                for (int i = 0; i < 8; i++) {
                    int nx = ux + dx[i];
                    int ny = uy + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || A[nx][ny] == '0') continue;
                    if (!used[nx][ny]) {
                        used[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == '0' || used[i][j]) continue;
                bfs(i, j);
                ans++;
            }
        }
        cout << "Image number " << T++ << " contains " << ans << " war eagles." << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}