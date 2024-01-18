/*  In the Name of ALLAH, the most gracious, the most merciful  */

// EQUAL2 - Equality Etiquette

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll diff = llabs(a - b);
    ll L = 0, R = N;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (M * (M + 1) / 2 >= diff) R = M;
        else L = M + 1;
    }
    int ans = L;
    for (int i = 0; i < 3; i++, L++) {
        ll x = L * (L + 1) / 2;
        if (x % 2 == diff % 2) {
            ans = L;
            break;
        }
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