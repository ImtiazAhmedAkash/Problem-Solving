/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rotate

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    auto ans = a;
    for (int i = 1; i < n; i++) {
        ans[0][i] = a[0][i - 1];
        ans [i][n - 1] = a[i - 1][n - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        ans[n - 1][i] = a[n - 1][i + 1];
        ans[i][0] = a[i + 1][0];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}