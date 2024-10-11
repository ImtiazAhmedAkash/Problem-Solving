/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Maximize the Largest Component (Easy Version)

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
    for (auto &x : A) cin >> x;

    map<pair<int, int>, int> M;
    vector par(n, vector<pair<int, int>>(m, {-1, -1}));
    int cnt = 0;
    auto dfs = [&](auto &&self, int x, int y, int px, int py) -> void {
        if (x < 0 || x >= n || y < 0 || y >= m || A[x][y] == '.' || par[x][y] != make_pair(-1, -1)) return;
        par[x][y] = {px, py};
        cnt++;
        for (int i = 0; i < 4; i++) {
            self(self, x + dx[i], y + dy[i], px, py);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '#' && par[i][j] == make_pair(-1, -1)) {
                cnt = 0;
                dfs(dfs, i, j, i, j);
                M[{i, j}] = cnt;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        set<pair<int, int>> st;
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.') {
                cur++;
            } else {
                st.insert(par[i][j]);
            }
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m || A[x][y] == '.') continue;
                st.insert(par[x][y]);
            }
        }
        for (auto &[a, b] : st) {
            cur += M[{a, b}];
        }
        ans = max(ans, cur);
    }

    for (int j = 0; j < m; j++) {
        int cur = 0;
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            if (A[i][j] == '.') {
                cur++;
            } else {
                st.insert(par[i][j]);
            }
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m || A[x][y] == '.') continue;
                st.insert(par[x][y]);
            }
        }
        for (auto &[a, b] : st) {
            cur += M[{a, b}];
        }
        ans = max(ans, cur);
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}