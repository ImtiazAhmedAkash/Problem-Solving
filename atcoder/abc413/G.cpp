/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// G - Big Banned Grid

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

vector<int> dx = {-1, +0, +1, +0, -1, -1, +1, +1};
vector<int> dy = {+0, +1, +0, -1, -1, +1, -1, +1};

void solve() {
    int h, w, k;
    cin >> h >> w >> k;
    set<pair<int, int>> blocked, used;
    queue<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        blocked.insert({x, y});
        if (x == h || y == 1) {
            q.push({x, y});
            used.insert({x, y});
        }
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == 1 || y == w) {
            cout << "No" << nl;
            return;
        }
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > h || ny <= 0 || ny > w) continue;
            if (blocked.count({nx, ny}) && !used.count({nx, ny})) {
                q.push({nx, ny});
                used.insert({nx, ny});
            }
        }
    }
    
    cout << "Yes" << nl;
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