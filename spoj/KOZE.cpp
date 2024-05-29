/*  In the Name of ALLAH, the most gracious, the most merciful  */

// KOZE - Sheep

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
    int s = 0, w = 0;
    bool escape = false;
    
    auto dfs = [&](auto&& self, int i, int j) -> void {
        used[i][j] = true;
        if (i == 0 || j == 0 || i + 1 == n || j + 1 == m) escape = true;
        
        if (A[i][j] == 'k') s++;
        else if (A[i][j] == 'v') w++;
        
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || y < 0 || x >= n || y >= m || A[x][y] == '#' || used[x][y]) continue;
            self(self, x, y);
        }
    };
    
    int sheep = 0, wolf = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '#' || used[i][j]) continue;
            s = 0, w = 0;
            escape = false;
            dfs(dfs, i, j);
            
            if (escape) {
                sheep += s;
                wolf += w;
                continue;
            }
            
            if (w < s) sheep += s;
            else wolf += w;
        }
    }
    
    cout << sheep << " " << wolf << nl;
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