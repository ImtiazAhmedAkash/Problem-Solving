/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 469 - Wetlands of Florida

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
    vector<string> A, B;
    string s;
    while (getline(cin, s) && !s.empty()) {
        if (isalpha(s.front())) {
            A.push_back(s);
        } else if (isdigit(s.front())) {
            B.push_back(s);
        }
    }

    int n = A.size();
    int m = A[0].size();
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<int>> ans(n, vector<int>(m));

    auto bfs = [&](int x, int y) -> void {
        queue<pair<int, int>> Q;
        int cnt = 0;
        Q.push({x, y});
        parent[x][y] = {x, y};
        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            cnt++;
            for (int i = 0; i < 8; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == 'L') continue;
                if (parent[nx][ny] == make_pair(-1, -1)) {
                    parent[nx][ny] = {x, y};
                    Q.push({nx, ny});
                }
            }
        }
        ans[x][y] = cnt;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'W' && parent[i][j] == make_pair(-1, -1)) {
                bfs(i, j);
            }
        }
    }

    for (auto s : B) {
        stringstream ss(s);
        int x, y;
        ss >> x >> y;
        --x, --y;
        auto [a, b] = parent[x][y];
        cout << ans[a][b] << nl;
    }
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