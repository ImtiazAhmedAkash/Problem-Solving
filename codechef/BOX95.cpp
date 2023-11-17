/*  In the Name of ALLAH, the most gracious, the most merciful  */

// BOX95 - Boxes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    multiset<ll> ms;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ms.insert(x);
    }
    ll ans = 1;
    ll val = *(ms.rbegin());
    ms.erase(ms.find(val));

    while (!ms.empty()) {
        ll m = *(ms.begin());
        if (m <= val) {
            val ^= m;
            ms.erase(ms.begin());
        } else {
            ans++;
            val = *(ms.rbegin());
            ms.erase(ms.find(val));
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