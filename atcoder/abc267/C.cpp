/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Index × A(Continuous ver.)

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
    int n, m;
    cin >> n >> m;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<ll> pref(n + 1);
    partial_sum(A.begin(), A.end(), pref.begin());
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += A[i] * i;
    }
    ll cur = ans;
    for (int i = m + 1; i <= n; i++) {
        cur += A[i] * m;
        cur -= pref[i - 1] - pref[i - m - 1];
        ans = max(ans, cur);
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