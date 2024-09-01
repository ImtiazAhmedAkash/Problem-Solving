/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Transportation Expenses

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e16;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    auto check = [&](ll mid) -> bool {
        ll have = k;
        for (auto &x : A) {
            ll y = min(mid, (ll)x);
            if (y > have) {
                return false;
            }
            have -= y;
        }
        return true;
    };

    ll L = 0, R = INF;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }

    if (R > k) {
        cout << "infinite" << nl;
    } else {
        cout << R << nl;
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