/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Trulimero Trulicina

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

vector<int> dx = {-1, +0, +1, +0};
vector<int> dy = {+0, +1, +0, -1};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    queue<pair<int, int>> q;
    int cnt = n * m / k;
    for (int i = 1; i <= k; i++) {
        q.push({i, cnt});
    }
    
    vector ans(n, vector<int>(m));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            while (true) {
                auto [a, b] = q.front();
                q.pop();
                bool ok = true;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (ans[nx][ny] == a) ok = false;
                }
                if (ok) {
                    ans[x][y] = a;
                    b--;
                    if (b) q.push({a, b});
                    break;
                }
                else {
                    q.push({a, b});
                }
            }
            
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j + 1 == m];
        }
    }
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