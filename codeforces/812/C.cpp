/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sagheer and Nubian Market

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
    int n, s;
    cin >> n >> s;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    auto check = [&](int mid) -> bool {
        auto B = A;
        for (int i = 1; i <= n; i++) {
            B[i] += 1LL * i * mid;
        }
        sort(B.begin(), B.end());
        ll cur = 0;
        for (int i = 1; i <= mid; i++) {
            cur += B[i];
        }
        if (s < cur) return false;
        ans = cur;
        return true;
    };

    int L = 0, R = n;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    cout << R << " " << ans << nl;
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