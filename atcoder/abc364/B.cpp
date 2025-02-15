/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Grid Walk

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// U -> R -> D -> L direction
vector<int> dx = {-1, +0, +1, +0};
vector<int> dy = {+0, +1, +0, -1};
string direction = "URDL";

void solve() {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    --x, --y;
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    string s;
    cin >> s;
    
    for (auto &c : s) {
        int indx = direction.find(c);
        int nx = x + dx[indx];
        int ny = y + dy[indx];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || A[nx][ny] == '#') continue;
        x = nx, y = ny;
    }
    
    cout << x + 1 << " " << y + 1 << nl;
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