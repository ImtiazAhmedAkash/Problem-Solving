/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Torus Path

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    vector A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            ans += A[i][j];
        }
    }

    int mini = inf;
    for (int i = 0; i < n; i++) {
        mini = min(mini, A[i][n - i - 1]);
    }
    ans -= mini;
    cout << ans << nl;
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