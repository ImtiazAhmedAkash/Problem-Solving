/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Circle Perimeter

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

    // returns the number of points y (y > 0) such that x * x + y * y < r * r (for one quadrant)
    auto binary_search = [&](int x, int r) -> int {
        int L = 0, R = n;
        while (L < R) {
            int M = L + (R - L + 1) / 2;
            if (1LL * x * x + 1LL * M * M < 1LL * r * r) {
                L = M;
            } else {
                R = M - 1;
            }
        }
        return R;
    };

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += binary_search(i, n + 1) - binary_search(i, n);
    }
    cout << ans * 4 << nl;
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