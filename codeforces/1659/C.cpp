/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Line Empire

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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<ll> suff(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = 1LL * (n - i) * (A[i + 1] - A[i]);
        suff[i] += suff[i + 1];
    }

    ll ans = INF;
    for (int i = 0; i <= n; i++) {
        ll cur = 1LL * a * A[i] + 1LL * b * (A[i] + suff[i]);
        ans = min(ans, cur);
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