/*  In the Name of ALLAH, the most gracious, the most merciful  */

// M<=ab

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 1000005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, m;
    cin >> n >> m;
    
    ll ans = INF;
    for (ll i = 1; i <= n; i++) {
        ll x = (m + i - 1) / i;
        if (x <= n) ans = min(ans, i * x);
        if (i > x) break;
    }
    
    if (ans == INF) ans = -1;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}