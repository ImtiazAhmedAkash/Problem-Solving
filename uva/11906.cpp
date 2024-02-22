/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11906 - Knight in a War Grid

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<bool>> water(n, vector<bool>(m, false));
    int w;
    cin >> w;
    while (w--) {
        int x, y;
        cin >> x >> y;
        water[x][y] = true;
    }

    vector<vector<bool>> used(n, vector<bool>(m, false));
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    vector<int> dx = {-a, -a, +a, +a, +b, -b, +b, -b};
    vector<int> dy = {+b, -b, +b, -b, -a, -a, +a, +a};

    auto bfs = [&](int x, int y) -> void {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        used[x][y] = true;
        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            set<pair<int, int>> st;
            for (int i = 0; i < 8; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || water[nx][ny]) continue;
                st.insert({nx, ny});
            }
            for (auto [nx, ny] : st) {
                cnt[nx][ny]++;
                if (!used[nx][ny]) {
                    used[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    };

    bfs(0, 0);
    vector<int> ans(2, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0 || cnt[i][j]) {
                ans[cnt[i][j] % 2]++;
            }
        }
    }
    cout << ans.front() << " " << ans.back() << nl;
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