/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Another Permutation Problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = i;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        auto b = a;
        reverse(b.begin() + i, b.end());
        ll tmp = 0, maxi = 0;
        for (int j = 1; j <= n; j++) {
            ll val = b[j] * j;
            tmp += val;
            maxi = max(maxi, val);
        }
        tmp -= maxi;
        ans = max(ans, tmp);
    }
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