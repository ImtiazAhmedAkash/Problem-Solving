/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Drunken Maze

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

vector<int> dx = {-1, +0, +1, +0};
vector<int> dy = {+0, +1, +0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    
    int sx = -1, sy = -1, tx = -1, ty = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'S') {
                sx = i, sy = j;
            }
            else if (A[i][j] == 'T') {
                tx = i, ty = j;
            }
        }
    }
    
    vector dist(n + 1, vector(m + 1, vector(5, vector<int>(5, inf))));
    min_heap<array<int, 5>> pq;
    pq.push({0, sx, sy, 4, 0}); // {distance, x-axis, y-axis, last-direction, remaining moves}
    while (!pq.empty()) {
        auto [d, x, y, last, rem] = pq.top();
        pq.pop();
        if (x == tx && y == ty) {
            cout << d << nl;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '#') continue;
            if (last == i && rem && d + 1 < dist[nx][ny][last][rem - 1]) {
                dist[nx][ny][last][rem - 1] = d + 1;
                pq.push({d + 1, nx, ny, i, rem - 1});
            }
            else if (last != i && d + 1 < dist[nx][ny][i][2]) {
                dist[nx][ny][i][2] = d + 1;
                pq.push({d + 1, nx, ny, i, 2});
            }
        }
    }
    
    cout << -1 << nl;
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