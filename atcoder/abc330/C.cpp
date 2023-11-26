/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimize Abs 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const ll N = 2e5 + 5;

void solve() {
    ll d;
    cin >> d;
    ll ans = d;
    
    auto square = [&](ll x, ll y) {
        return (x * x) + (y * y);
    };
    
    for (ll x = 0; x * x <= d; x++) {
        ll y = d - (x * x);
        y = sqrtl(y);
        ans = min({ans, abs(d - square(x, y)), abs(d - square(x, y + 1)), abs(d - square(x, y - 1))});
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