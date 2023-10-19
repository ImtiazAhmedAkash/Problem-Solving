/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Perfect Square

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
    vector<string> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int cur = A[i][j] + A[j][n - 1 - i] + A[n - 1 - i][n - 1 - j] + A[n - 1 - j][i];
            int maxi = max({A[i][j], A[j][n - 1 - i], A[n - 1 - i][n - 1 - j], A[n - 1 - j][i]});
            ans += 4 * maxi - cur;
        }
    }
    cout << ans << nl;
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