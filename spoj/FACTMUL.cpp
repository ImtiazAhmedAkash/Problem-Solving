/*  In the Name of ALLAH, the most gracious, the most merciful  */

// FACTMUL - Product of factorials

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int128 __int128
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 109546051211;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    ll ans = 1, cur = 1;
    for (int i = 2; i <= n; i++) {
        cur = cur * i % mod;
        ans = (int128)ans * cur % mod;
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