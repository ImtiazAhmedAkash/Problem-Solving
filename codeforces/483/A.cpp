/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Counterexample

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
    ll l, r;
    cin >> l >> r;
    
    for (ll a = l; a <= r; a++) {
        for (ll b = a + 1; b <= r; b++) {
            for (ll c = b + 1; c <= r; c++) {
                if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) != 1) {
                    cout << a << " " << b << " " << c << nl;
                    return;
                }
            }
        }
    }
    
    cout << -1 << nl;
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