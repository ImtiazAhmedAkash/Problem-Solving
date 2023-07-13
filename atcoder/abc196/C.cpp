/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Doubled

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n;
    cin >> n;
    ll ans = 0, i = 1, mul = 10;
    while(1) {
        ll val = (i * mul) + i;
        if (val > n) break;
        ans++, i++;
        if (i == mul) mul *= 10;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}