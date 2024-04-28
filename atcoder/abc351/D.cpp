/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Grid and Magnet

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
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '#') {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || A[nx][ny] == '#') continue;
                    A[nx][ny] = '!';
                }
            }
        }
    }

    int cnt = 0;
    vector used(n, vector<bool>(m, false));
    set<pair<int, int>> st;

    auto dfs = [&](auto&& self, int x, int y) -> void {
        cnt++;
        if (A[x][y] == '!') {
            st.insert({x, y});
            return;
        }
        used[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || A[nx][ny] == '#') continue;
            if (!used[nx][ny] && st.find({nx, ny}) == st.end()) {
                self(self, nx, ny);
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != '#' && !used[i][j]) {
                dfs(dfs, i, j);
                ans = max(ans, cnt);
                cnt = 0;
                st.clear();
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