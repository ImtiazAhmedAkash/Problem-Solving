/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tales of a Sort

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
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    
    ll ans = 0, indx = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            indx = i;
            break;
        }
    }
    
    if (indx != -1) ans = *max_element(a.begin(), a.begin() + indx + 1);
    
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