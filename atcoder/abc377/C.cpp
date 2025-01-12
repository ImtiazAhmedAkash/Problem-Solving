/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Avoid Knight Attack

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// knight moves
vector<int> dx = {+2, +1, -1, -2, -2, -1, +1, +2};
vector<int> dy = {+1, +2, +2, +1, -1, -2, -2, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> A(m);
    for (auto &[x, y] : A) cin >> x >> y;
    
    set<pair<int, int>> st;
    for (auto &[x, y] : A) {
        st.insert({x, y});
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            st.insert({nx, ny});
        }
    }
    
    cout << 1LL * n * n - st.size() << nl;
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