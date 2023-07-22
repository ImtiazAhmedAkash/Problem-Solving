/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cardboard for Pictures

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    
    auto check = [&] (ll mid) {
        __int128_t area = 0;
        for (int i = 0; i < n; i++) {
            ll side = 2 * mid + a[i];
            area += (side * side);
            if (area > c) return area;
        }
        
        return area;  
    };
    
    ll L = 0, R = 1e9;
    ll ans = 0;
    while (L <= R) {
        ll M = L + (R - L) / 2;
        __int128_t area = check(M);
        if (area == c) {
            ans = M;
            break;
        } else if (area < c) {
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
    cout << ans << nl;
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