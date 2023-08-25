/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Kolya and Movie Theatre

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    multiset<ll> ms;
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 0) continue;
        if (ms.size() == m) {
            ll x = *ms.begin();
            sum -= x;
            ms.erase(ms.begin());
        }
        sum += a[i];
        ll tmp = sum - (i * d);
        ans = max(ans, tmp);
        ms.insert(a[i]);
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