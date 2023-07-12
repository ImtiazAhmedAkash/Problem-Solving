/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Inflation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    ll total_cur_inflation = accumulate(a.begin(), a.end(), 0LL);
    ll ans = 0;
    for (int i = n - 1; i > 0; i--) {
        total_cur_inflation -= a[i];
        ll new_total_inflation = ((100 * a[i]) + (k - 1)) / k;
        ll tmp = max(0LL, new_total_inflation - total_cur_inflation);
        ans += tmp;
        total_cur_inflation += tmp;
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