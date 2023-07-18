/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Omkar and Last Class of Math

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n;
    cin >> n;
    
    auto lcm = [&] (ll a, ll b) {
        return (a * b) / gcd(a, b);
    };
    
    ll LCM = n - 1, ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (lcm(i, n - i) < LCM) {
                LCM = lcm(i, n - i);
                ans = i;
            }
            ll div = n / i;
            if (lcm(div, n - div) < LCM) {
                LCM = lcm(div, n - div);
                ans = div;
            }
        }
    }
    cout << ans << " " << n - ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}