/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Black Cells

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
    vector<ll> A(n);
    for (auto &x : A) cin >> x;

    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    ll ans = INF;
    ll diff = 0;
    for (int i = 1; i < n; i += 2) {
        diff = max(diff, A[i] - A[i - 1]);
    }
    ans = min(ans, diff);

    if (n & 1) {
        auto check = [&](ll mid) -> ll {
            int need = 0;
            for (int i = 0; i < n; i++) {
                if (i + 1 < n && A[i] + mid < A[i + 1]) {
                    need++;
                } else {
                    i++;
                }
            }
            return need <= 1;
        };

        ll L = 0, R = INF;
        while (L < R) {
            ll M = L + (R - L) / 2;
            if (check(M)) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        ans = min(ans, L);
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