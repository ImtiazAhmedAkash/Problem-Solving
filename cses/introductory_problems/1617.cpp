/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bit Strings

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 1000000007;

void solve() {
    ll n;
    cin >> n;

    ll ans = 1;
    for (ll i = 1; i <= n; i++)
        ans = (ans * 2) % mod;

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}