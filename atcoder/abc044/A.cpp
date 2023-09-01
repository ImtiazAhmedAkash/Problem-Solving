/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tak and Hotels (ABC Edit)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int ans = min(n, k) * x;
    ans += max(0, n - k) * y;
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