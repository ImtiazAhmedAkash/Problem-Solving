/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lazy Faith

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
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> S(a), T(b);
    for (auto &x : S) cin >> x;
    for (auto &x : T) cin >> x;

    while (q--) {
        ll x;
        cin >> x;

        ll ls = -INF, rs = INF, lt = -INF, rt = INF;
        int indx = lower_bound(S.begin(), S.end(), x) - S.begin();
        if (indx != a) rs = S[indx];
        if (indx != 0) ls = S[indx - 1];

        indx = lower_bound(T.begin(), T.end(), x) - T.begin();
        if (indx != b) rt = T[indx];
        if (indx != 0) lt = T[indx - 1];

        ll ans = INF;
        ans = min({
            max(rs, rt) - x,                // right shrine, right temple
            x - min(ls, lt),                // left shrine, left temple
            rs - lt + min(x - lt, rs - x),  // right shrine, left temple
            rt - ls + min(x - ls, rt - x)   // left shrine, right temple
        });

        cout << ans << nl;
    }
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