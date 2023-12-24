/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Socks 2

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
    int n, k;
    cin >> n >> k;
    vector<ll> A(k);
    for (auto &x : A) cin >> x;
    ll ans;
    if (k % 2 == 0) {
        ans = 0;
        for (int i = 1; i < k; i += 2) {
            ans += A[i] - A[i - 1];
        }
    } else {
        ans = INF;
        vector<ll> pref(k + 1), suff(k + 2);
        for (int i = 2; i < k; i += 2) {
            pref[i] = pref[i - 2];
            pref[i] += A[i - 1] - A[i - 2];
        }
        for (int i = k - 2; i >= 0; i -= 2) {
            suff[i] = suff[i + 2];
            suff[i] += A[i + 1] - A[i];
        }
        ans = min(pref[k - 1], suff[1]);
        for (int i = 2; i < k; i += 2) {
            ans = min(ans, pref[i] + suff[i + 1]);
        }
    }
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