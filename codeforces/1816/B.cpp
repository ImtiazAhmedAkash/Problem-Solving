/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Grid Reconstruction

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
    vector ans(2, vector<int>(n));
    int cur = 1;
    for (int i = 1, j = 0; j < n; j++) {
        ans[i][j] = cur++;
        i ^= 1;
    }
    for (int i = 1, j = 1; j < n; j++) {
        ans[i][j] = cur++;
        i ^= 1;
    }
    ans[0][0] = 2 * n;
    ans[1][n - 1] = 2 * n - 1;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << nl;
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