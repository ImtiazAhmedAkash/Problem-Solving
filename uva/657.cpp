/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 657 - The die is cast

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
    int n, m, T = 1;
    while (cin >> m >> n && m && n) {
        vector<string> A(n);
        for (auto& x : A) cin >> x;

        vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
        auto parent_bfs = [&](int x, int y) -> void {
            queue<pair<int, int>> Q;
            Q.push({x, y});
            parent[x][y] = {x, y};
            while (!Q.empty()) {
                auto [ux, uy] = Q.front();
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = ux + dx[i];
                    int ny = uy + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] != 'X') continue;
                    if (parent[nx][ny] == make_pair(-1, -1)) {
                        parent[nx][ny] = {x, y};
                        Q.push({nx, ny});
                    }
                }
            }
        };

        vector<vector<bool>> used(n, vector<bool>(m, false));
        auto bfs = [&](int x, int y) -> int {
            queue<pair<int, int>> Q;
            set<pair<int, int>> st;
            Q.push({x, y});
            used[x][y] = true;
            while (!Q.empty()) {
                auto [ux, uy] = Q.front();
                Q.pop();
                if (parent[ux][uy] != make_pair(-1, -1)) {
                    st.insert(parent[ux][uy]);
                }
                for (int i = 0; i < 4; i++) {
                    int nx = ux + dx[i];
                    int ny = uy + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '.') continue;
                    if (!used[nx][ny]) {
                        used[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }

            return (int)st.size();
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 'X' && parent[i][j] == make_pair(-1, -1)) {
                    parent_bfs(i, j);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] != '.' && !used[i][j]) {
                    ans.push_back(bfs(i, j));
                }
            }
        }

        sort(ans.begin(), ans.end());

        cout << "Throw " << T++ << nl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}