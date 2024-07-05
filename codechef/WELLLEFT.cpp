/*  In the Name of ALLAH, the most gracious, the most merciful  */

// WELLLEFT - Amphibian Escape

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
    int n, k, h;
    cin >> n >> k >> h;

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= h) {
            ans += n;
            continue;
        }

        int L = 0, R = i - 1;
        while (L < R) {
            int M = L + (R - L + 1) / 2;
            int dist = max(0, h - i);
            if (1LL * (i - M) * (k - 1) >= dist) {
                L = M;
            } else {
                R = M - 1;
            }
        }
        ans += R;
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