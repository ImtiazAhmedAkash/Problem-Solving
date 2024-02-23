/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11953 - Battleships

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
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    vector<vector<bool>> used(n, vector<bool>(n, false));
    auto bfs = [&](int x, int y) -> void {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        used[x][y] = true;

        bool right = false, down = false;
        if (y + 1 < n && A[x][y + 1] != '.')
            right = true;
        else if (x + 1 < n && A[x + 1][y] != '.')
            down = true;

        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            if (right && uy + 1 < n && A[ux][uy + 1] != '.' && !used[ux][uy + 1]) {
                used[ux][uy + 1] = true;
                Q.push({ux, uy + 1});
            } else if (down && ux + 1 < n && A[ux + 1][uy] != '.' && !used[ux + 1][uy]) {
                used[ux + 1][uy] = true;
                Q.push({ux + 1, uy});
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 'x' && !used[i][j]) {
                bfs(i, j);
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