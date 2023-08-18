/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fancy Coins

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll m, k, a, b;
    cin >> m >> k >> a >> b;
    
    ll ans = 0;
    ll x = m / k;
    ll rem = m % k;
    if (rem < a) {
        a -= rem;
        x -= (a / k);
    } else {
        ans += (rem - a);
    }
    ans += max(0LL, x - b);
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}