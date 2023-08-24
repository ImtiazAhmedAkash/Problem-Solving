/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Power of Points

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
    vector<pair<ll, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i].first;
    }
    vector<ll> ans(n + 1); 
    for (int i = 1; i <= n; i++) {
        ll val = a[i].first;
        int indx = a[i].second;
        ll right = (pref[n] - pref[i - 1]) - val * (n - i + 1) + (n - i + 1);
        ll left = val * (i - 1) - pref[i - 1] + (i - 1);
        ans[indx] = left + right;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << nl;
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