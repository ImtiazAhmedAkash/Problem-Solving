/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Interesting Sequence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 9e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, x;
    cin >> n >> x;

    auto range_and = [&](ll x, ll y) -> ll {
        ll ans = 0;
        while (x && y && __lg(x) == __lg(y)) {
            ll z = (1LL << __lg(x));
            ans += z;
            x -= z;
            y -= z;
        }
        return ans;
    };

    ll L = n, R = INF;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (range_and(n, M) <= x) {
            R = M;
        } else {
            L = M + 1;
        }
    }

    cout << (range_and(n, L) == x ? L : -1) << nl;
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