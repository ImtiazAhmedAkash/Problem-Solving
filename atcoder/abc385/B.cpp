/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Santa Claus 1

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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    --x, --y;
    vector<string> A(h);
    for (auto &x : A) cin >> x;
    
    string s;
    cin >> s;
    
    set<pair<int, int>> st;
    for (auto &c : s) {
        int nx = x, ny = y;
        if (c == 'U') nx--;
        if (c == 'D') nx++;
        if (c == 'L') ny--;
        if (c == 'R') ny++;
        
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || A[nx][ny] == '#') continue;
        
        x = nx, y = ny;
        if (A[x][y] == '@') {
            st.insert({x, y});
        }
    }
    
    cout << x + 1 << " " << y + 1 << " " << st.size() << nl;
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