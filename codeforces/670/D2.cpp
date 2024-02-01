/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Magic Powder - 2

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    auto check = [&](ll mid) -> bool {
        ll need = 0;
        for (int i = 0; i < n; i++) {
            ll cur = 1LL * A[i] * mid;
            need += max(0LL, cur - B[i]);
            if (k < need) return false;
        }
        return true;
    };

    ll L = 0, R = 1e10;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    cout << R << nl;
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