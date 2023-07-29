/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Makes and The Product

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

ll ncr(ll n, ll r) {
    ll res = 1;
    if (n == 0) return 0;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, ll> cnt;
    for (auto &x : a) {
        cin >> x;
        cnt[x]++;
    }
    sort(a.begin(), a.end());
    
    ll ans = 0;
    if (a[0] == a[2]) ans = ncr(cnt[a[0]], 3);
    else if (a[0] != a[1] && a[1] != a[2]) ans = (ncr(cnt[a[0]], 1) * ncr(cnt[a[1]], 1) * ncr(cnt[a[2]], 1));
    else if (a[0] == a[1]) ans = ncr(cnt[a[0]], 2) * ncr(cnt[a[2]], 1);
    else if (a[1] == a[2]) ans = ncr(cnt[a[0]], 1) * ncr(cnt[a[1]], 2);
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}