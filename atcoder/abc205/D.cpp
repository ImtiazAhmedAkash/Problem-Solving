/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Kth Excluded

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
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;

    auto check = [&](ll mid, ll k) -> bool {
        ll valid = mid - (upper_bound(A.begin(), A.end(), mid) - A.begin());
        return k <= valid;
    };

    while (q--) {
        ll k;
        cin >> k;
        ll L = 1, R = INF + N;
        while (L < R) {
            ll M = L + (R - L) / 2;
            if (check(M, k)) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        cout << L << nl;
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