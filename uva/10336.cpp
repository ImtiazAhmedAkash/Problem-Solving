/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 10336 - Rank the Languages

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

    vector<vector<bool>> used(n, vector<bool>(m, false));
    auto bfs = [&](int x, int y) -> void {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        used[x][y] = true;
        while (!Q.empty()) {
            auto [ux, uy] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = ux + dx[i];
                int ny = uy + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] != A[x][y]) continue;
                if (!used[nx][ny]) {
                    used[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    };

    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j]) {
                bfs(i, j);
                cnt[A[i][j] - 'a']++;
            }
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            ans.push_back({cnt[i], i});
        }
    }
    sort(ans.begin(), ans.end(), [&](pair<int, int> x, pair<int, int> y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    });

    for (auto [x, y] : ans) {
        cout << (char)(y + 'a') << ": " << x << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "World #" << t << nl;
        solve();
    }

    return 0;
}