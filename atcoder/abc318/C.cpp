/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Blue Spring

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = INF, sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += a[i];
        ans = min(ans, sum + (n - i + d - 1) / d * p);
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