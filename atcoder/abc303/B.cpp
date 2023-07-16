/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Discord

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    
    int ans = n * (n - 1) / 2;
    
    set<pair<int, int>> st;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j + 1 < n; j++) {
            int x = min(a[i][j], a[i][j + 1]);
            int y = max(a[i][j], a[i][j + 1]);
            st.insert({x, y});
        }
    }
    
    cout << ans - (int) st.size() << nl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}