/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Buying a TV Set

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll GCD = gcd(x, y);
    x /= GCD;
    y /= GCD;
    cout << min(a / x, b / y) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}