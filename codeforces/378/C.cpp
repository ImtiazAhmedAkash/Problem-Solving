/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Maze

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    int empty = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.') empty++;
        }
    }

    int good = empty - k;
    vector used(n, vector<bool>(m, false));
    auto dfs = [&](auto&& self, int i, int j) -> void {
        used[i][j] = true;
        good--;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || y < 0 || x >= n || y >= m || A[x][y] == '#' || used[x][y]) continue;
            if (good) self(self, x, y);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '.' && good) {
                dfs(dfs, i, j);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (A[i][j] == '#' || used[i][j] ? A[i][j] : 'X');
        }
        cout << nl;
    }
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